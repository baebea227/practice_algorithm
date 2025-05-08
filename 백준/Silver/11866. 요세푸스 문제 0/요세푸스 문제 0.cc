#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    queue<int> q;
    for (int i=0; i<n; i++) {
        q.push(i+1);
    }
    int k;
    cin >> k;
    cout << "<";
    
    int index = 0;
    while (q.size() > 1) {
        index = (index+k-1) % q.size();
        for (int i=0; i<k-1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">" << '\n';
}