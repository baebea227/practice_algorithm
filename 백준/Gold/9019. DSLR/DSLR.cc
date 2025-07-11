#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int D(int n) {
    n = n * 2;
    if(n > 9999) n %= 10000;
    return n;
}

int S(int n) {
    if(n == 0) n = 9999;
    else n--;
    return n;
}

int L(int n) {
    int temp = n / 1000;
    n *= 10;
    n %= 10000;
    n += temp;
    return n;
}

int R(int n) {
    int temp = n % 10;
    n /= 10;
    n += temp * 1000;
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;

        queue<pair<int, string>> q;
        vector<int> visited(10000, false);
        q.push({a, ""});
        visited[a] = true;

        while(!q.empty()) {
            auto qFront = q.front();
            if(qFront.first == b) break;

            int (*ops[4])(int) = {D, S, L, R};
            char opChar[4] = {'D', 'S', 'L', 'R'};
            
            for (int i=0; i<4; i++) {
                int next = ops[i](qFront.first);
                if(!visited[next]) {
                    q.push({next, qFront.second + opChar[i]});
                    visited[next] = true;
                }
            }

            q.pop();
        }

        cout << q.front().second << '\n';
    }
}