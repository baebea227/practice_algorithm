#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int left = 0; int right = n-1;
    int ansLeft; int ansRight; 
    int currSum; int ansSum = 2e9;

    while(left < right) {
        currSum = arr[left] + arr[right];

        if(abs(currSum) < abs(ansSum)) {
            ansSum = currSum;
            ansLeft = left; ansRight = right;
        }

        if(currSum < 0) left++;
        else right--;
    }

    cout << arr[ansLeft] << " " << arr[ansRight] << '\n';
}