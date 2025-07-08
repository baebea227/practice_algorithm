#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> &v, int user, int target, int n) {
    queue<int> q;
    vector<bool> visited(n+1, false);

    q.push(user);
    visited[user] = true;

    int cnt = 1;
    while(!q.empty()) {
        int qSize = q.size();
        for (int i=0; i<qSize; i++) {
            int qFront = q.front();
            for(int j=0; j<v[qFront].size(); j++) {
                if(v[qFront][j] == target) return cnt;
                if(!visited[v[qFront][j]]) {
                    q.push(v[qFront][j]);
                    visited[v[qFront][j]] = true;
                }
            }
            q.pop();
        }
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int minSum = n*n;
    int minNum = 1;
    for (int user=1; user<=n; user++) {
        int sum = 0;
        for(int target=1; target<=n; target++) {
            if(user == target) continue;
            sum += bfs(v, user, target, n);
        }
        if(sum < minSum) {
            minSum = sum;
            minNum = user;
        }
    }
    
    cout << minNum << '\n';
}