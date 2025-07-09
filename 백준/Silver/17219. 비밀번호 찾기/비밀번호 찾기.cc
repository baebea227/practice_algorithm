#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<string, string> myMap;

    string key, value;
    for (int i=0; i<n; i++) {
        cin >> key >> value;
        myMap[key] = value;
    }

    for (int i=0; i<m; i++) {
        cin >> key;
        cout << myMap[key] << '\n';
    }
}