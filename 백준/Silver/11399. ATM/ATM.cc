#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> arr;
    for (int i=0, input; i<n; i++) {
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    
    int sum=0;
    for (int i=0, j=n; i<n; i++, j--) {
        sum += arr[i] * j;
    }
    cout << sum << '\n';
}