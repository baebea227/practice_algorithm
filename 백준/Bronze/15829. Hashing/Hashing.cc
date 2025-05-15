#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int l;
    cin >> l;
    string s;
    cin >> s;
    
    int m = 1234567891;
    long long r = 1;
    long long result=0;
    for (int i=0; i<l; i++) {
        result += ((s[i] - 'a' + 1) * r) % m;
        r *= 31;
        r %= m;
        result %= m;
    }
    cout << result << '\n';
}