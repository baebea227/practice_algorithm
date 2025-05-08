#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int arr[n];
    int sum = 0;
    map<int, int> mapArr;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
        mapArr[arr[i]] += 1;
    }
    int avg = sum/n;
    if (sum >= 0 && sum%n>=0.5*n) avg++;
    else if (sum < 0 && sum%n<=-0.5*n) avg--;
    cout << avg << '\n';

    sort(arr, arr+n);
    cout << arr[n/2] << '\n';

    int maxCount=0;
    int maxNum;
    for (int e : arr) {
        if (mapArr[e] > maxCount) {
            maxCount = mapArr[e];
            maxNum = e;
        }
    }
    set<int> setArr;
    for (int e : arr) {
        if (mapArr[e] == maxCount) {
            setArr.insert(e);
        }
    }
    if(setArr.size() == 1) cout << *setArr.begin() << '\n';
    else {
        cout << *next(setArr.begin(),1) << '\n';
    }

    cout << arr[n-1]-arr[0] << '\n';
}