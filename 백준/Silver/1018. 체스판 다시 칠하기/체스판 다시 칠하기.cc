#include <iostream>
using namespace std;

int drawChessBoard(int chessBoard[8][8]) {
    int cnt=0;
    for (int i=0; i<8; i+=2) {
        for (int j=0; j<8; j+=2) {
            if (chessBoard[i][j] != 'W') {
                cnt++;
            }
        }
    }
    for (int i=0; i<8; i+=2) {
        for (int j=1; j<8; j+=2) {
            if (chessBoard[i][j] != 'B') {
                cnt++;
            }
        }
    }
    for (int i=1; i<8; i+=2) {
        for (int j=1; j<8; j+=2) {
            if (chessBoard[i][j] != 'W') {
                cnt++;
            }
        }
    }
    for (int i=1; i<8; i+=2) {
        for (int j=0; j<8; j+=2) {
            if (chessBoard[i][j] != 'B') {
                cnt++;
            }
        }
    }
    if (cnt > 32) {
        cnt = 64 - cnt;
    }
    return cnt;
}
int main() {
    int x, y;
    cin >> x >> y;
    char chessBoard[x][y];
    int min = 64;

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            cin >> chessBoard[i][j];
        }
    }
    for (int i=0; i<x-7; i++) {
        for (int j=0; j<y-7; j++) {
            int temp[8][8];
            for (int k=0; k<8; k++) {
                for (int l=0; l<8; l++) {
                    temp[k][l] = chessBoard[i+k][j+l];
                }
            }
            int cnt = drawChessBoard(temp);
            if (cnt < min) {
                min = cnt;
            }
        }
    }

    cout << min << endl;
}
