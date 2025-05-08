#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nt;
    cin >> nt;

    string func;

    int arr[10000];
    int n;
    int index=-1;

    for (int t=0; t<nt; t++) {
        cin >> func;
        if (func=="push") {
            cin >> n;
            index++;
            arr[index] = n;
        }
        else if (func=="pop") {
            if (index==-1) cout << -1 << '\n';
            else {
                cout << arr[index] << '\n';
                index--;
            }
        }
        else if (func=="size") {
            cout << index+1 << '\n';
        }
        else if (func=="empty") {
            if (index==-1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (func=="top") {
            if (index==-1) cout << -1 << '\n';
            else cout << arr[index] << '\n';
        }
    }
}