#include <bits/stdc++.h>
using namespace std;

int Find(vector<int>& parent, int x) {
    if(parent[x] != x)
        parent[x] = Find(parent, parent[x]);
    return parent[x];
}

bool Unite(vector<int>& parent, int a, int b) {
    int pa = Find(parent, a);
    int pb = Find(parent, b);
    if(pa == pb) return false;
    parent[pb] = pa;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n);
    for(int i=0; i<n; i++) parent[i] = i;

    int isCycle = 0;
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        if(isCycle == 0) {
            if(!Unite(parent, a, b))
                isCycle = i;
        }
    }

    cout << isCycle << '\n';
}