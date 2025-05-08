#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
   pair<int, int>arr[n];
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }
    sort(arr, arr+n);
    for (int i=0; i<n; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
}