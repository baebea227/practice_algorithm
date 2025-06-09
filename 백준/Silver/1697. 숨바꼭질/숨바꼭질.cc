#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (n >= k) {
        cout << n-k << '\n';
    }
    else {
        queue<int> q;
        vector<bool> visited(k*2+1, 0);
    
        q.push(n);
        visited[n] = 1;
    
        int cnt = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for (int i=0; i<qSize; i++) {
                int qFront = q.front();
                int dx[3] = {qFront+1, qFront-1, qFront*2};
                q.pop();
                for (int d : dx) {
                    if(d == k) {
                        cout << cnt+1 << '\n';
                        return 0;
                    }
                    if(d >= 0 && d <= k*2 && !visited[d]) {
                        q.push(d);
                        visited[d] = 1;
                    }
                }
            }
            cnt++;
        }
    }
}