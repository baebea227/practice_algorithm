#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, nN;
    cin >> n;
    unordered_set<int> numbers;
    for (int i=0; i<n; i++) {
        cin >> nN;
        numbers.insert(nN);
    }
    int m, mN;
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> mN;
        cout << (numbers.find(mN) != numbers.end()) << '\n';
    }
}