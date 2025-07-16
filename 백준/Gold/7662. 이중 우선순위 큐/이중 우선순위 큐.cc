#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while(tc--) {
        int k;
        cin >> k;
        
        map<int, int> m;

        while(k--) {
            char method;
            int n;
            cin >> method >> n;

            if (method == 'I') {
                m[n]++;
            }
            else if (method == 'D' && !m.empty()) { 
                if (n == 1) {
                    auto it = m.rbegin();
                    if(--(it->second) == 0) m.erase(it->first);
                }
                else if (n == -1) {
                    auto it = m.begin();
                    if(--(it->second) == 0) m.erase(it->first);
                }
            }
        }

        if (m.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << m.rbegin()->first << " " << m.begin()->first << "\n";
        }
    }
}