#include <iostream>
#include <string>
using namespace std;

int main() {
    while (1) {
        string s;

        getline(cin, s);
        if (s == "0") break;
        if (s.size() == 1) {
            cout << "yes" << endl;
            continue;
        }
        for (int i=0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                cout << "no" << endl;
                break;
            }
            if (i == s.size() / 2 - 1) cout << "yes" << endl;
        }
    }
}