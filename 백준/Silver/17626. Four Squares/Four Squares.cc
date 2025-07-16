#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i*i<=n; i++) {
        v.push_back(i*i);
    }

    for(int i : v) {
        for(int j : v) {
            for(int k : v) {
                for(int l : v) {
                    if(i+j+k+l == n) {
                        cout << (i != 0) + (j != 0) + (k != 0) + (l != 0) << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    
}