#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    vector<int> sumArr(n+1);
    cin >> arr[0];
    sumArr[0] = arr[0];
    for (int i=1; i<n; i++) {
        cin >> arr[i];
        sumArr[i] = sumArr[i-1] + arr[i];
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1) cout << sumArr[b-1] << '\n';
        else cout << sumArr[b-1] - sumArr[a-2] << '\n';
    }
}