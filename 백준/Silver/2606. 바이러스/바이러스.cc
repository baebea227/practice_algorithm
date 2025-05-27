#include <iostream>
#include <vector>
using namespace std;

void DFS(const vector<vector<int>>& links, vector<int>& visited, int node) {
    visited[node] = true;
    for (int i=0; i<links[node].size(); i++) {
        if(!visited[links[node][i]]) {
            DFS(links, visited, links[node][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int computerNum, linkedNum;
    cin >> computerNum >> linkedNum;
    
    vector<int> visited(computerNum+1, false);
    vector<vector<int>> links(computerNum+1);
    int a, b;
    for (int i=0; i<linkedNum; i++) {
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    DFS(links, visited, 1);

    int cnt = 0;
    for(bool b : visited) {
        if(b) cnt++;
    }
    cout << cnt-1 << '\n';
}