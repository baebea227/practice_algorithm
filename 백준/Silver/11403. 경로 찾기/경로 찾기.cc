#include <iostream>
#include <queue>
using namespace std;

bool arr[100][100];

bool bfs(int start, int target, int n) {
    bool visited[n] = {0};
    queue<int> q;

    visited[start] = 1;
    q.push(start);
    while(!q.empty()) {
        for(int i=0; i<n; i++) {
            if(arr[q.front()][i]) {
                if(i == target) return 1;
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        q.pop();
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << bfs(i, j, n) << " ";
        }
        cout << '\n';
    }
}