#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char ch) {

        // Row check
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch)
                return false;
        }

        // Column check
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return false;
        }

        // 3x3 Box check
        int sr = row - row % 3;
        int sc = col - col % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[sr + i][sc + j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {

        if (row == 9)
            return true;

        if (col == 9)
            return solve(board, row + 1, 0);

        if (board[row][col] != '.')
            return solve(board, row, col + 1);

        for (char ch = '1'; ch <= '9'; ch++) {
            if (check(board, row, col, ch)) {
                board[row][col] = ch;

                if (solve(board, row, col + 1))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    obj.solveSudoku(board);

    cout << "Solved Sudoku:\n";
    for (auto &row : board) {
        for (char x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}