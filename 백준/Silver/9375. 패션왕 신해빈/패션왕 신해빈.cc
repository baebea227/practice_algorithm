#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    
    while(tc--) {
        int n;
        cin >> n;

        map<string, int> m;
        for(int i=0; i<n; i++) {
            string a, b;
            cin >> a >> b;
            m[b]++;
        }

        int result = 1;

        for(const auto& [key, cnt] : m) {
            result *= cnt+1;
        }

        cout << result-1 << '\n';
    }
}