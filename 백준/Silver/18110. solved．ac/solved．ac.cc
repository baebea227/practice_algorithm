#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    map<int, int> nums;
    int num;
    for (int i=0; i<n; i++) {
        cin >> num;
        nums[num]++;
    }

    int skipSize = round(n * 15.0 / 100);
    for (int i=0, j=1; i<skipSize; ) {
        if (nums[j] > 0) {
            nums[j]--;
            i++;
        }
        else j++;
    }
    for (int i=0, j=30; i<skipSize; ) {
        if (nums[j] > 0) {
            nums[j]--;
            i++;
        }
        else j--;
    }

    float sum = 0;
    for (int i=0, j=0; i<n-skipSize*2; ) {
        if (nums[j] > 0) {
            sum += j * nums[j];
            i += nums[j];
            j++;
        }
        else j++;
    }

    if (!n) {
        cout << 0 << '\n';
        return 0;
    }
    cout << round(sum / (n-skipSize*2)) << '\n';
}