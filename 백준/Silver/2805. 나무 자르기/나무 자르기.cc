#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    int high = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] > high) high = arr[i];
    }
    int low = 0;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        unsigned int sum = 0;
        for (int i=0; i<n; i++) {
            if(sum <= m && arr[i] > mid) sum += arr[i] - mid;
        }
        if (sum >= m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << high << '\n';
}