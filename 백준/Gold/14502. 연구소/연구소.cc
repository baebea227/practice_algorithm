#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Lab {
    int n, m;
    vector<vector<int>> grid;
    vector<pair<int,int>> viruses;
    vector<pair<int,int>> empties;

    Lab(int n, int m) : n(n), m(m), grid(n, vector<int>(m)) {}
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(const Lab& lab, const vector<int>& walls) {
    vector<vector<int>> g = lab.grid;
    for(auto pos : walls) {
        g[lab.empties[pos].first][lab.empties[pos].second] = 1;
    }

    queue<pair<int,int>> q;
    for(auto v : lab.viruses) {
        q.push({v.first, v.second});
    }

    while(!q.empty()) {
        auto qFront = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = qFront.first + dx[i];
            int ny = qFront.second + dy[i];
            if(nx >= 0 && nx < lab.n && ny >= 0 && ny < lab.m) {
                if(g[nx][ny] == 0) {
                    g[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    int cnt = 0;
    for(auto &i : g) {
        for(auto &j : i) {
            if(j == 0) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Lab lab(n, m);

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> lab.grid[i][j];
            if(lab.grid[i][j] == 0) lab.empties.push_back({i, j});
            else if(lab.grid[i][j] == 2) lab.viruses.push_back({i, j});
        }
    }

    int result = 0;
    int E = lab.empties.size();
    for(int i=0; i<E; i++) {
        for(int j=i+1; j<E; j++) {
            for (int k=j+1; k<E; k++) {
                result = max(result, bfs(lab, vector<int>{i, j, k}));
            }
        }
    }
    cout << result << '\n';
}