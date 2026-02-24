#include <bits/stdc++.h>
using namespace std;

bool p[4000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> primes;
    for(int i=2; i*i<=n; i++) {
        if(!p[i]) {
            for(long long j=i*i; j<=n; j+=i) {
                p[j] = true;
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(!p[i]) primes.push_back(i);
    }

    int cnt = 0; int sum = 0;
    int left = 0, right = 0;
    int end = primes.size();
    while(true) {
        if(sum >= n) {
            if(sum == n) cnt++;

            sum -= primes[left++];
        }
        else {
            if(right == end) break;

            sum += primes[right++];
        }
    }

    cout << cnt << '\n';
}