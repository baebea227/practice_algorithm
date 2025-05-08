#include <iostream>
using namespace std;

int isN (int n) {
    int sum=n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int num=0;
    for (int i=1; i<n; i++) {
        if (isN(i) == n) {
            num = i;
            break;
        }
    }
    cout << num << '\n';
}