#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0, sum = 0, ans = n+1;
    for(int right=0; right<n; right++) {
        sum += arr[right];
        while(sum >= s) {
            ans = min(ans, right-left+1);
            sum -= arr[left++];
        }
    }
    
    cout << (ans == n+1 ? 0 : ans) << '\n';
}