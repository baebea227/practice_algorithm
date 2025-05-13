#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, num;
    int cnt[10001] = {0};
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num;
        cnt[num]++;
    }
    for (int i=0; i<10001; i++) {
        for (int j=0; j<cnt[i]; j++) {
            cout << i << '\n';
        }
    }
}