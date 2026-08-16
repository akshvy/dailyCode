#include <bits/stdc++.h>
using namespace std;

// Request States
enum State {
    STATE_ARRIVED,       // Ready for P PRE
    STATE_P_PRE_RUNNING,
    STATE_P_UP_QUEUED,
    STATE_READY_P_PROC,  // Ready for P PROC
    STATE_P_PROC_RUNNING,
    STATE_P_DOWN_QUEUED,
    STATE_READY_P_POST,  // Ready for P POST
    STATE_P_POST_RUNNING,
    STATE_READY_D_PRE,   // Ready for D PRE
    STATE_D_PRE_RUNNING,
    STATE_D_UP_QUEUED,
    STATE_READY_D_PROC,  // Ready for D PROC
    STATE_D_PROC_RUNNING,
    STATE_D_DOWN_QUEUED,
    STATE_READY_D_POST,  // Ready for D POST
    STATE_D_POST_RUNNING,
    STATE_FINISHED
};

struct Request {
    int id;
    long long l_in;
    int assigned_remote = -1;
    State state = STATE_ARRIVED;
};

// System Configuration
int K, num_layers;
long long bytes_per_token;
double S, latency_in_ms, bandwidth_gbps;
double SLO1, SLO2, tp_UB, tp_base, dist_base, w_tp, w_c;

// State management
unordered_map<int, Request> reqs;
bool edge_busy = false;
vector<bool> remote_busy;
int next_remote_rr = 0;

void solve() {
    // 1. Read startup configuration
    if (!(cin >> K >> S >> latency_in_ms >> bandwidth_gbps >> bytes_per_token >> num_layers)) {
        return;
    }
    cin >> SLO1 >> SLO2 >> tp_UB >> tp_base >> dist_base >> w_tp >> w_c;

    remote_busy.assign(K, false);

    // 2. Read Task-Time Table
    int N;
    if (!(cin >> N)) return;
    for (int i = 0; i < N; ++i) {
        long long bsz;
        double p_pre, p_proc, p_post, d_pre, d_proc, d_post;
        cin >> bsz >> p_pre >> p_proc >> p_post >> d_pre >> d_proc >> d_post;
    }

    // 3. Interactive Event Loop
    string token;
    while (cin >> token) {
        if (token == "END") {
            break;
        }

        // Parse timestamp and event count
        double current_time = stod(token);
        int event_count;
        cin >> event_count;

        for (int i = 0; i < event_count; ++i) {
            string ev_type;
            cin >> ev_type;

            if (ev_type == "ARR") {
                int rid;
                long long lin;
                cin >> rid >> lin;
                Request r;
                r.id = rid;
                r.l_in = lin;
                r.state = STATE_ARRIVED;
                reqs[rid] = r;
            } 
            else if (ev_type == "TDN") {
                string srv, task;
                cin >> srv >> task;

                if (task == "P") {
                    string sub;
                    cin >> sub;
                    if (sub == "PRE") {
                        int rem, rid;
                        double dur;
                        cin >> rem >> rid >> dur;
                        edge_busy = false;
                        reqs[rid].state = STATE_P_UP_QUEUED;
                    } else if (sub == "PROC") {
                        int ls, le, rem, rid;
                        double dur;
                        cin >> ls >> le >> rem >> rid >> dur;
                        remote_busy[rem] = false;
                        reqs[rid].state = STATE_P_DOWN_QUEUED;
                    } else if (sub == "POST") {
                        int rem, rid;
                        double dur;
                        cin >> rem >> rid >> dur;
                        edge_busy = false;
                        reqs[rid].state = STATE_READY_D_PRE;
                    }
                } else if (task == "D") {
                    string sub;
                    cin >> sub;
                    if (sub == "PRE") {
                        int dummy, m;
                        cin >> dummy >> m;
                        vector<int> rids(m);
                        for (int &id : rids) cin >> id;
                        double dur;
                        cin >> dur;
                        edge_busy = false;
                        for (int id : rids) {
                            reqs[id].state = STATE_D_UP_QUEUED;
                        }
                    } else if (sub == "PROC") {
                        int rem, m;
                        cin >> rem >> m;
                        vector<int> rids(m);
                        for (int &id : rids) cin >> id;
                        double dur;
                        cin >> dur;
                        remote_busy[rem] = false;
                        for (int id : rids) {
                            reqs[id].state = STATE_D_DOWN_QUEUED;
                        }
                    } else if (sub == "POST") {
                        int dummy, m;
                        cin >> dummy >> m;
                        vector<int> rids(m);
                        for (int &id : rids) cin >> id;
                        double dur;
                        cin >> dur;
                        edge_busy = false;
                        for (int id : rids) {
                            if (reqs[id].state != STATE_FINISHED) {
                                reqs[id].state = STATE_READY_D_PRE;
                            }
                        }
                    }
                }
            } 
            else if (ev_type == "XDN") {
                string dir, kind;
                int rem, m;
                long long sz;
                cin >> dir >> rem >> sz >> kind >> m;
                vector<int> rids(m);
                for (int &id : rids) cin >> id;

                for (int id : rids) {
                    if (kind == "PRE") {
                        if (dir == "UP") reqs[id].state = STATE_READY_P_PROC;
                        else if (dir == "DOWN") reqs[id].state = STATE_READY_P_POST;
                    } else if (kind == "DEC") {
                        if (dir == "UP") reqs[id].state = STATE_READY_D_PROC;
                        else if (dir == "DOWN") reqs[id].state = STATE_READY_D_POST;
                    }
                }
            } 
            else if (ev_type == "FIN") {
                int rid;
                cin >> rid;
                reqs[rid].state = STATE_FINISHED;
            }
        }

        // 4. Scheduling Decisions for Available Resources
        vector<string> scheduled_cmds;

        // Schedule Edge / Local tasks (Priority: D POST > P POST > D PRE > P PRE)
        if (!edge_busy) {
            int target_rid = -1;

            // Priority 1: D POST
            for (auto &kv : reqs) {
                if (kv.second.state == STATE_READY_D_POST) {
                    target_rid = kv.first;
                    break;
                }
            }
            if (target_rid != -1) {
                edge_busy = true;
                reqs[target_rid].state = STATE_D_POST_RUNNING;
                scheduled_cmds.push_back("E D POST -1 1 " + to_string(target_rid));
            } else {
                // Priority 2: P POST
                for (auto &kv : reqs) {
                    if (kv.second.state == STATE_READY_P_POST) {
                        target_rid = kv.first;
                        break;
                    }
                }
                if (target_rid != -1) {
                    edge_busy = true;
                    reqs[target_rid].state = STATE_P_POST_RUNNING;
                    scheduled_cmds.push_back("E P POST " + to_string(reqs[target_rid].assigned_remote) + " " + to_string(target_rid));
                } else {
                    // Priority 3: D PRE
                    for (auto &kv : reqs) {
                        if (kv.second.state == STATE_READY_D_PRE) {
                            target_rid = kv.first;
                            break;
                        }
                    }
                    if (target_rid != -1) {
                        edge_busy = true;
                        reqs[target_rid].state = STATE_D_PRE_RUNNING;
                        scheduled_cmds.push_back("E D PRE -1 1 " + to_string(target_rid));
                    } else {
                        // Priority 4: P PRE
                        for (auto &kv : reqs) {
                            if (kv.second.state == STATE_ARRIVED) {
                                target_rid = kv.first;
                                break;
                            }
                        }
                        if (target_rid != -1) {
                            edge_busy = true;
                            int assigned = next_remote_rr;
                            next_remote_rr = (next_remote_rr + 1) % K;
                            reqs[target_rid].assigned_remote = assigned;
                            reqs[target_rid].state = STATE_P_PRE_RUNNING;
                            scheduled_cmds.push_back("E P PRE " + to_string(assigned) + " " + to_string(target_rid));
                        }
                    }
                }
            }
        }

        // Schedule Remote Cloud workers (C0 ... C(K-1))
        for (int k = 0; k < K; ++k) {
            if (remote_busy[k]) continue;

            // Prioritize active token generation (D PROC) over prefill (P PROC)
            int d_target = -1;
            for (auto &kv : reqs) {
                if (kv.second.assigned_remote == k && kv.second.state == STATE_READY_D_PROC) {
                    d_target = kv.first;
                    break;
                }
            }

            if (d_target != -1) {
                remote_busy[k] = true;
                reqs[d_target].state = STATE_D_PROC_RUNNING;
                scheduled_cmds.push_back("C" + to_string(k) + " D PROC " + to_string(k) + " 1 " + to_string(d_target));
            } else {
                int p_target = -1;
                for (auto &kv : reqs) {
                    if (kv.second.assigned_remote == k && kv.second.state == STATE_READY_P_PROC) {
                        p_target = kv.first;
                        break;
                    }
                }
                if (p_target != -1) {
                    remote_busy[k] = true;
                    reqs[p_target].state = STATE_P_PROC_RUNNING;
                    scheduled_cmds.push_back("C" + to_string(k) + " P PROC 0 " + to_string(num_layers) + " " + to_string(k) + " " + to_string(p_target));
                }
            }
        }

        // 5. Output response and flush immediately
        cout << scheduled_cmds.size() << "\n";
        for (const string &cmd : scheduled_cmds) {
            cout << cmd << "\n";
        }
        cout << flush;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}