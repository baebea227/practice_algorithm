#include <iostream>
#include <vector>
using namespace std;

vector<int> graph;

void postorder(int left, int right) {
    if(left > right) return;
    int root = graph[left];

    int i=left+1;
    while(i <= right && graph[i] < root) i++;

    postorder(left+1, i-1);
    postorder(i, right);

    cout << graph[left] << '\n';
}

void solve() {
    int n;
    while(cin >> n) {
        graph.push_back(n);
    }

    postorder(0, graph.size()-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}