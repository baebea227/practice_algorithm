#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int nt;
    cin >> nt;
    
    while(nt--) {
        int n, m;
        cin >> n >> m;
        queue<pair<int,int>> que;
        map<int, int, greater<int>> priority;

        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            que.push({i, p});
            priority[p]++;
        }

        int cnt=1;
        while (true) {
            if (que.front().second==priority.begin()->first) {
                if (que.front().first == m) break;
                else {
                    que.pop();
                    cnt++;
                    if(priority.begin()->second==1) priority.erase(priority.begin());
                    else priority.begin()->second--;
                }
            }
            else {
                que.push(que.front());
                que.pop();
            }
        }
        cout << cnt << '\n';
    }
}