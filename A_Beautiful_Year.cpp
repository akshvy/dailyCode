#include <iostream>
#include <string>
using namespace std;

int main() {
    int year;
    cin >> year;

    while (true) {
        year++;
        string s = to_string(year);

        if (s[0] != s[1] &&
            s[0] != s[2] &&
            s[0] != s[3] &&
            s[1] != s[2] &&
            s[1] != s[3] &&
            s[2] != s[3]) {
            cout << year << endl;
            break;
        }
    }

    return 0;
}
