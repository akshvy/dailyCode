#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int matrix[5][5];
    int targetRow = 0, targetCol = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                targetRow = i;
                targetCol = j;
            }
        }
    }

    int moves = abs(targetRow - 2) + abs(targetCol - 2);
    cout << moves << endl;

    return 0;
}