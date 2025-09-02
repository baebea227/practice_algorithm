#include <iostream>
#include <vector>
using namespace std;

vector<string> board;

void draw(int n, int x, int y) {
    if(n == 1) {
        board[y][x] = '*';
        return;
    }

    int div = n/3;
    for(int dx=0; dx<3; dx++) {
        for(int dy=0; dy<3; dy++) {
            if(dx==1 && dy==1) continue;
            draw(div, x + dx*div, y + dy*div);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    board.assign(N, string(N, ' '));
    draw(N, 0, 0);

    for(string row : board) {
        cout << row << '\n';   
    }
}