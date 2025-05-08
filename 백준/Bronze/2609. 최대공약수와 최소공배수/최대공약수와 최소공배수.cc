#include <iostream>
using namespace std;

int main() {
    int n, m;
    int maxN = 1, minN = 1;
    cin >> n >> m;
    if (n == m) {
        cout << n << " " << n << endl;
        return 0;
    }
    else {
        for (int i=2; i<=n; i++) {
            if (n % i == 0 && m % i == 0) {
                n /= i;
                m /= i;
                minN *= i;
                i = 1;
            }
        }
        maxN = minN * n * m;
        cout << minN << " " << maxN << endl;
    }
    return 0;
}