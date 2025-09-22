#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
set<int> s;
vector<int> seq;

void backtrack(int depth) {
    if(depth == M) {
        for(int i : seq) cout << i << " ";
        cout << '\n';
        return;
    }
    
    for(int i : s) {
        if(seq.empty() || i >= seq.back()) {
            seq.push_back(i);
            backtrack(depth + 1);
            seq.pop_back();
        }
    }
}

void solve() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        s.insert(n);
    }

    backtrack(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}