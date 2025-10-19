// https://www.hackerrank.com/contests/oriental-campus-181025/challenges/sudoku-prover

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isValidSudoku(const vector<vector<int>>& board) {
    // Check rows and columns
    for (int i = 0; i < 9; ++i) {
        set<int> rowSet, colSet;
        for (int j = 0; j < 9; ++j) {
            int rowVal = board[i][j];
            int colVal = board[j][i];

            if (rowVal < 1 || rowVal > 9 || colVal < 1 || colVal > 9)
                return false;

            if (rowSet.count(rowVal) || colSet.count(colVal))
                return false;

            rowSet.insert(rowVal);
            colSet.insert(colVal);
        }
    }

    // Check 3x3 boxes
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            set<int> boxSet;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int val = board[boxRow + i][boxCol + j];
                    if (boxSet.count(val))
                        return false;
                    boxSet.insert(val);
                }
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < 9; ++j) {
            board[i][j] = line[j] - '0'; // convert char to int
        }
    }

    if (isValidSudoku(board)) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }

    return 0;
}
/*
417369825
632158947
958724316
825437169
791586432
346912758
289643571
573291684
164875293
correct
*/