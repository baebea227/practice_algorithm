#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i=0, a, b; i<n; i++) {
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }
    sort(arr.begin(), arr.end());

    int result = 1;
    int last = arr[0].second;
    for (int i=1; i<n; i++) {
        if(arr[i].first >= last) {
            result++;
            last = arr[i].second;
        }
        else if (arr[i].second < last) {
            last = arr[i].second;
        }
    }
    
    cout << result << '\n';
}