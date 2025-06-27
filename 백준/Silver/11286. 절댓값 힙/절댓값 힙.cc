#include <iostream>
#include <queue>
using namespace std;

struct Cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    priority_queue<int, vector<int>, Cmp> pq;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            pq.push(x);
        }
        else {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
}