#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int i=665;
    while (n > 0) {
        i++;
        if (to_string(i).find("666") != string::npos) {
            n--;
        }
    }
    cout << i << '\n';
}