#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    long long curSum; long long ansSum = 4e18;
    vector<long long> ans(3);

    for(int i=0; i<n; i++) {
        int left = i+1, right = n-1;

        while(left < right) {
            curSum = arr[left] + arr[right] + arr[i];

            if(abs(curSum) < abs(ansSum)) {
                ansSum = curSum;
                ans[0] = arr[i]; ans[1] = arr[left]; ans[2] = arr[right];
            }

            if(curSum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}