#include <iostream>
#include <vector>
using namespace std;

vector<int> whiteBlue(2, 0);

void cutBoard(const vector<vector<int>> &board, int n, int x, int y) {
    int startColor = board[x][y];
    bool isSame = true;
    for (int i=0; i<n && isSame; i++) {
        for (int j=0; j<n; j++) {
            if (board[x+i][y+j] != startColor) {
                isSame = false;
                break;
            }
        }
    }
    if(isSame) whiteBlue[startColor] += 1;
    else {
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                cutBoard(board, n/2, x+i*(n/2), y+j*(n/2));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    cutBoard(board, n, 0, 0);

    cout << whiteBlue[0] << '\n' << whiteBlue[1] << '\n';
}