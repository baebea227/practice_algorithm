#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int maxNum = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    double sum=0;
    for (int i=0; i<n; i++) {
        sum += arr[i] * 100 / (double)maxNum;

    }
    cout << sum / n << endl;
    return 0;
}