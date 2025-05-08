#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    cin >> m;
    unordered_map<int, int> mMap;

    int number;
    for (int i=0; i<m; i++) {
        cin >> number;
        mMap[number] += 1;
    }

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> number;
        cout << (mMap.count(number) ? mMap.at(number) : 0) << " ";
    }
}