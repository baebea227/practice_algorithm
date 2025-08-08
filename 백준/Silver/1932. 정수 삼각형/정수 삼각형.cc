#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> prev(n, 0), curr(n, 0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int input;
            cin >> input;
            if(j == 0) curr[j] = input + prev[0];
            else if(j == i) curr[j] = input + prev[j-1];
            else curr[j] = input + max(prev[j], prev[j-1]);
        }
        prev = curr;
    }

    cout << *max_element(prev.begin(), prev.end()) << '\n';
}