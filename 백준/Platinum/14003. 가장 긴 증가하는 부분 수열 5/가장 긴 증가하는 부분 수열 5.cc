#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> lis;
    vector<int> pos(n);

    for(int i=0; i<n; i++) {
        int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

        if(idx == lis.size()) {
            lis.push_back(arr[i]);
        }
        else {
            lis[idx] = arr[i];
        }
        pos[i] = idx;
    }

    int len = lis.size();
    cout << len << '\n';
    
    vector<int> ans(len--);

    for(int i=n-1; i>=0; i--) {
        if(pos[i] == len) {
            ans[len--] = arr[i];
        }

        if(len < 0) break;
    }

    for(int i : ans) cout << i << " ";
    cout << '\n';
}