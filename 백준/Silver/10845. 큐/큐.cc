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
    int rear=0, front=0;

    for (int t=0; t<nt; t++) {
        cin >> func;
        if (func=="push") {
            cin >> n;
            arr[rear++] = n;
        }
        else if (func=="pop") {
            cout << (rear==front ? -1 : arr[front++]) << '\n';
        }
        else if (func=="size") {
            cout << rear-front << '\n';
        }
        else if (func=="empty") {
            cout << (rear==front ? 1 : 0) << '\n';
        }
        else if (func=="front") {
            cout << (rear==front ? -1 : arr[front]) << '\n';
        }
        else if (func=="back") {
            cout << (rear==front ? -1 : arr[rear-1]) << '\n';
        }
    }
}