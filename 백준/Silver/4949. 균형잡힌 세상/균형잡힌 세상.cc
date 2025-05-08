#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    while(true) {
        getline(cin, line);
        if (line == ".") break;

        stack<char> stk;
        for (char c : line) {
            if (c == '(' || c == '[') stk.push(c);
            if (c == ')' || c == ']') {
                if (!stk.empty() && stk.top() == ((c == ')') ? '(' : '[')) stk.pop();
                else {
                    cout << "no" << '\n';
                    break;
                }
            }
            if (c == '.') {
                if (stk.empty()) cout << "yes" << '\n';
                else cout << "no" << '\n';
                break;
            }
        }
    }
}