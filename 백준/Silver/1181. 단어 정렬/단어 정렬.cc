#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n, [](const string &a, const string &b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    });
    for (int i=0; i<n-1; i++) {
        if (arr[i] == arr[i+1]) {
            continue;
        }
        else {
            cout << arr[i] << endl;
        }
    }
    cout << arr[n-1] << endl;
}