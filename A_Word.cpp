#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count_lower = 0, count_upper = 0;

    for (char c : s) {
        if (islower(c))
            count_lower++;
        else
            count_upper++;
    }

    if (count_lower >= count_upper) {
        for (char &c : s)
            c = tolower(c);
    } else {
        for (char &c : s)
            c = toupper(c);
    }

    cout << s;
    return 0;
}
