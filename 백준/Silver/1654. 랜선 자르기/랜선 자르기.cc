#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n;
    cin >> k >> n;
    
    int arr[k];
    unsigned int high=0;
    for (int i=0; i<k; i++) {
        cin >> arr[i];
        if (high < arr[i]) {
            high = arr[i];
        }
    }
    unsigned int low = 1;
    unsigned int mid;
    
    while (low <= high) {
        int cnt=0;
        mid = (low + high) / 2;
        for (int i=0; i<k; i++) {
            cnt += arr[i]/mid;
        }
        if (cnt >= n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << high << '\n';
}