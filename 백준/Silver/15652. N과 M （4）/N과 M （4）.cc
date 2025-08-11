#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> path;

void dfs(int depth, int start) {
    if(depth == m) {
        for(int i : path) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=start; i<=n; i++) {
        path.push_back(i);
        dfs(depth + 1, i);
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    dfs(0, 1);
}