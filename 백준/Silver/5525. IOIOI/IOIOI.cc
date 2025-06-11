#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> m >> s;
    
    int cnt = 0;
    int Pcnt = 0;
    for(int i=0; i<m; i++) {
        if(s[i] == 'I') {
            while(i+2<m) {
                if(s[i+1] == 'O' && s[i+2] == 'I') {
                    Pcnt++;
                    i+=2;
                }
                else {
                    break;
                }
            }
            if(Pcnt >= n) cnt += Pcnt-n+1;
            Pcnt = 0;
        }
    }
    cout << cnt << '\n';
}