#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N+1, vector<int>(N+1));
    for(int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> board[i][j];
        }
    }

    // (1, 1) ~ (i, j)의 누적합
    vector<vector<int>> prefix(N+1, vector<int>(N+1));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            prefix[i][j] = board[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    // 누적합을 이용한 계산
    for(int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1] << '\n';
    }
}