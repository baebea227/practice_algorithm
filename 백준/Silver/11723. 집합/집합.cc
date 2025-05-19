#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    int mySet = 0;
    string s;
    int x;
    while(t--) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            mySet |= (1 << (x - 1));
        }
        else if (s == "remove") {
            cin >> x;
            mySet &= ~(1 << (x - 1));
        }
        else if (s == "check") {
            cin >> x;
            cout << (mySet & (1 << (x - 1)) ? 1 : 0 ) << '\n';
        }
        else if (s == "toggle") {
            cin >> x;
            mySet ^= (1 << (x - 1));
        }
        else if (s == "all") {
            mySet = (1 << 20) - 1;
        }
        else if (s == "empty") {
            mySet = 0; 
        }
    }
}