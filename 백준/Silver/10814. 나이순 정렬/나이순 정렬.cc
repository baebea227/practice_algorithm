#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nt;
    cin >> nt;
    
    vector<pair<int, string>> n;
        int a;
        string b;
    for (int t=0; t<nt; t++) {
        cin >> a >> b;
        n.push_back({a, b});
    }
    stable_sort(n.begin(), n.end(), [](pair<int, string> a, pair<int, string> b) {
        return a.first < b.first;
    });
    for (auto p : n) {
        cout << p.first << " " << p.second << '\n';
    }
}