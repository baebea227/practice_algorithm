#include <iostream>
#include <stack>
#include <string>
using namespace std;

string checkVPS(string s) {
    stack<char> stk;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '(') stk.push('(');
        else if (s[i] == ')') {
            if (stk.empty()) return "NO";
            else stk.pop();
        }
    }
    if (stk.empty()) return "YES";
    else return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int n=0; n<t; n++) {
        string s;
        cin >> s;
        cout << checkVPS(s) << "\n";
    }
}