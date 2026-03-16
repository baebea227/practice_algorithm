#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, b, c;
};

vector<int> parent;

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return false;
    parent[fb] = fa;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Node> edges;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({--a, --b, c}); // 0-based
    }
    sort(edges.begin(), edges.end(), [](const Node& a, const Node& b){
        return a.c < b.c;
    });

    parent.resize(n);
    for(int i=0; i<n; i++) parent[i] = i;

    int cnt = 0;
    int answer = 0;
    for(Node curr : edges) {
        if(cnt >= n-2) break;
        
        if(unite(curr.a, curr.b)) {
            answer += curr.c;
            cnt++;
        }
    }

    cout << answer << '\n';
}