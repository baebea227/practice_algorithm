#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    string name;
    vector<string> names, result;

    for (int i=0; i<n; i++) {
        cin >> name;
        names.push_back(name);
    }
    sort(names.begin(), names.end());
    for (int i=0; i<m; i++) {
        cin >> name;
        if (binary_search(names.begin(), names.end(), name)) {
            result.push_back(name);
        }
    }
    sort(result.begin(), result.end());
    
    cout << result.size() << '\n';
    for (auto it : result) {
        cout << it << '\n';
    }
}