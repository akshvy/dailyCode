#include<iostream>
#include<string>
using namespace std;
int main() {
    string word;
    cin >> word;

    if (word.length() == 0) {
        cout << word << endl;
        return 0;
    }

    // Check if the first character is lowercase
    if (islower(word[0])) {
        // Convert the first character to uppercase
        word[0] = toupper(word[0]);
    }

    cout << word << endl;
    return 0;
}