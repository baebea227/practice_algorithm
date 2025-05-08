#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    stack<int> stk;
    vector<int> answer;

    stk.push(0);
    int it=1;
    for (int i=0; i<n; i++) {
        int m;
        cin >> m;

        while(stk.top() != m) {
            stk.push(it);
            answer.push_back('+');
            it++;
            if (it>n) break;
        }
        stk.pop();
        answer.push_back('-');
    }
    while(stk.top() != 0) {
        stk.pop();
        answer.push_back('-');
    }

    if(answer.size()==2*n) {
        for (char e : answer) {
            cout << e << '\n';
        }
    }
    else cout << "NO" << '\n';
}