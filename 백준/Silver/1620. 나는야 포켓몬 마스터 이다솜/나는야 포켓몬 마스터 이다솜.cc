#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    unordered_map<string, string> dogam;
    string input;
    for (int i=0; i<n; i++) {
        cin >> input;
        dogam[input] = to_string(i+1);
        dogam[to_string(i+1)] = input;
    }
    for (int i=0; i<m; i++) {
        cin >> input;
        cout << dogam[input] << '\n';
    }
}