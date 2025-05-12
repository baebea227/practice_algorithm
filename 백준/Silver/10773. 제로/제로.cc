#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    stack<int> stk;
    while(t--) {
        int n;
        cin >> n;
        if (!n) stk.pop();
        else stk.push(n);
    }
    int sum=0;
    while(!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    cout << sum << '\n';
}