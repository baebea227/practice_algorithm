#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string n;
    cin >> n;
    
    int weights[12] = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3};
    int sum = 0;
    int damagedIdx;
    for (int i=0; i<12; i++) {
        if(n[i] == '*') damagedIdx = i;
        else sum += (n[i]-'0') * weights[i];
    }
    for (int i=0; i<=9; i++) {
        int total = sum + i * weights[damagedIdx];
        if(n[12]-'0' == (10 - total % 10) % 10) {
            cout << i << '\n';
            return 0;
        }
    }
}