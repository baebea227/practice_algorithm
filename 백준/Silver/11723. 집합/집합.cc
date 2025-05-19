#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    int mySet[21] = {0};
    string s;
    int x;
    while(t--) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            mySet[x] = 1;
        }
        else if (s == "remove") {
            cin >> x;
            mySet[x] = 0;
        }
        else if (s == "check") {
            cin >> x;
            cout << mySet[x] << '\n';
        }
        else if (s == "toggle") {
            cin >> x;
            mySet[x] = mySet[x] ? 0 : 1;
        }
        else if (s == "all") {
            for (int i=0; i<21; i++) {
                mySet[i] = 1;
            }
        }
        else if (s == "empty") {
            for (int i=0; i<21; i++) {
                mySet[i] = 0;
            }
        }
    }
}