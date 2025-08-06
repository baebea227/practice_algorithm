#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> comb;

void solve(int length, int start) {
    if(length == m) {
        for(int i : comb) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=start; i<=n; i++) {
        comb.push_back(i);
        solve(length + 1, i + 1);
        comb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    solve(0, 1);
}