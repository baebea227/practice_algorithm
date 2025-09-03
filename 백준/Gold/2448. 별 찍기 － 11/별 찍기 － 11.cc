#include <iostream>
#include <vector>
using namespace std;

vector<string> board;

void draw(int n, int x, int y) {
    if(n == 3) {
        board[y][x] = '*';
        board[y+1][x+1] = '*'; board[y+1][x-1] = '*';
        for(int i=-2; i<=2; i++) board[y+2][x+i] = '*';
        return;
    }

    int half = n/2;
    draw(half, x, y);
    draw(half, x-half, y+half);
    draw(half, x+half, y+half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    board.assign(N, string(N*2-1, ' '));

    draw(N, N-1, 0);

    for(string &line : board) {
        cout << line << '\n';
    }
}