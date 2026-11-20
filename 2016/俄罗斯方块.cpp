#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> board(16, vector<int>(11, 0));

    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> x, y;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            int value;
            cin >> value;

            if (value == 1) {
                x.push_back(i);  // 原始行坐标
                y.push_back(j);  // 原始列坐标
            }
        }
    }

    int col;
    cin >> col;

    // 转换成方块在棋盘上的列坐标
    for (int k = 0; k < (int)y.size(); k++) {
        y[k] += col - 1;
    }

    int down = 0;  // 当前已经下降的行数

    while (true) {
        bool canFall = true;

        // 检查：在当前位置基础上，还能否再下降一行
        for (int k = 0; k < (int)x.size(); k++) {
            int nextRow = x[k] + down + 1;
            int column = y[k];

            if (nextRow > 15 || board[nextRow][column] == 1) {
                canFall = false;
                break;
            }
        }

        if (!canFall) {
            break;
        }

        down++;
    }

    // 确定最终位置后，再统一写入棋盘
    for (int k = 0; k < (int)x.size(); k++) {
        board[x[k] + down][y[k]] = 1;
    }

    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j > 1) cout << ' ';
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}