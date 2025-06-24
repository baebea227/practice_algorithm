#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string n;
    cin >> n;
    
    int sum = 0;
    string str = "";
    bool isMinus = false;

    int i=0;
    for (; i<n.length(); i++) {
        while(n[i] - '0' >= 0 && n[i] - '0' <= 9) {
            str += n[i];
            i++;
        }

        if (isMinus) {
            sum -= stoi(str);
            str = "";
        }
        else {
            sum += stoi(str);
            str = "";
        }

        if (n[i] == '-') {
            isMinus = true;
        }
    }
    cout << sum << '\n';
}