#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    long long arr[101];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    for (int tc=0; tc<t; tc++) {
        int n;
        cin >> n;

        for(int i=6; i<=n; i++) {
            arr[i] = arr[i-1] + arr[i-5];
        }
        cout << arr[n] << '\n';
    }
}