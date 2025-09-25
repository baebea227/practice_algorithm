#include <iostream>
#include <stack>
using namespace std;

int priority(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

void solve() {
    string line;
    cin >> line;

    stack<char> OpStack;
    for(char c : line) {
        if(c >= 'A' && c <= 'Z') cout << c;
        else if(c == '(') OpStack.push(c);
        else if(c == ')') {
            while(!OpStack.empty() && OpStack.top() != '(') {
                cout << OpStack.top();
                OpStack.pop();
            }
            OpStack.pop();
        }
        else {
            while(!OpStack.empty() && OpStack.top() != '(' && priority(OpStack.top()) >= priority(c)) {
                cout << OpStack.top();
                OpStack.pop();
            }
            OpStack.push(c);
        }
    }

    while(!OpStack.empty()) {
        cout << OpStack.top();
        OpStack.pop();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}