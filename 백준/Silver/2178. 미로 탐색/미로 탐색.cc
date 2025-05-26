#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i=0; i<n; i++) {
        cin >> board[i];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    board[0][0] = '0';

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int cnt = 1;
    while(!q.empty()) {
        
        int qSize = q.size();
        for (int i=0; i<qSize; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int j=0; j<4; j++) {
                int nX = x + dx[j];
                int nY = y + dy[j];

                if (nX >= n || nX < 0 || nY >= m || nY < 0) continue;

                if (board[nX][nY] == '1') {
                    if (nX == n-1 && nY == m-1) { 
                        cout << cnt+1 << '\n';
                        return 0;
                    }
                    board[nX][nY] = '0';
                    q.push({nX, nY});
                }
            }
        }
        cnt++;
    }
}