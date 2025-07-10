#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int shortcuts[101] = {0};

    for(int i=0; i<n+m; i++) {
        int a, b;
        cin >> a >> b;
        shortcuts[a] = b;
    }

    queue<int> q;
    bool visited[101] = {false};
    q.push(1);
    visited[1] = true;
    int cnt = 0;
    while(!q.empty()) {
        int qSize = q.size();
        for(int i=0; i<qSize; i++) {
            int qFront = q.front();
            for(int i=1; i<=6; i++) {
                int next = qFront + i;
                if(shortcuts[next]) next = shortcuts[next];
                if(next == 100) {
                    cout << cnt+1 << '\n';
                    return 0;
                }
                if(!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
            q.pop();
        }
        cnt++;
    }
}