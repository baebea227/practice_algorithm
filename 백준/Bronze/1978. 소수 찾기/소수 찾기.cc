#include <iostream>
using namespace std;

int isPrime(int num) {
    if (num < 2) { return 0; }
    for (int i=2; i*i <= num; i++) {
        if (num % i == 0) { return 0; }
    }
    return 1;
}

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        cnt += isPrime(num);
    }
    cout << cnt << endl;
}