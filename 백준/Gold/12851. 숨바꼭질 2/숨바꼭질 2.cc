#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    if(N >= K) {
        cout << N-K << " " << 1 << '\n';
        return 0;
    }

    int MAX = K*2+1;
    vector<int> time(MAX, -1);
    vector<int> ways(MAX, 0);
    queue<int> q;
    
    time[N] = 0;
    ways[N] = 1;
    q.push(N);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int next : {curr-1, curr+1, curr*2}) {
            if(next < 0 || next > MAX) continue;

            if(time[next] == -1) {
                time[next] = time[curr]+1;
                ways[next] = ways[curr];
                q.push(next);
            }
            else if(time[next] == time[curr]+1){
                ways[next] += ways[curr];
            }
        }
    }
    
    cout << time[K] << '\n' << ways[K] << '\n';

    return 0;
}