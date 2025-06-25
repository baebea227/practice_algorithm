#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    vector<int> sortedArr(n);
    map<int, int> m;
    for (int i=0, j=0; i<n; i++) {
        cin >> arr[i];
        sortedArr[i] = arr[i];
    }
    sort(sortedArr.begin(), sortedArr.end());
    
    for (int i=0, j=0; i<n; i++) {
        if (m.find(sortedArr[i]) == m.end()) {
            m[sortedArr[i]] = j;
            j++;
        }
    }

    for (int i=0; i<n; i++) {
        cout << m[arr[i]] << " ";
    }
}