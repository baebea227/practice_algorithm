#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find_parent(int a) {
    if(parent[a] != a) 
        parent[a] = find_parent(parent[a]);
    return parent[a];
}

void union_party(int a, int b) {
    int fa = find_parent(a);
    int fb = find_parent(b);
    if(fb != fa)
        parent[fb] = fa;
}

void solve() {
    int N, M;
    cin >> N >> M;
    
    parent.resize(N+1);
    for(int i=0; i<N+1; i++)
        parent[i] = i;
    
    int num_truth;
    cin >> num_truth;

    for(int i=0; i<num_truth; i++) {
        int person;
        cin >> person;

        union_party(0, person);
    }
        
    vector<vector<int>> parties(M);

    for(int i=0; i<M; i++) {
        int num_party;
        cin >> num_party;
        
        for(int j=0; j<num_party; j++) {
            int person;
            cin >> person;
            parties[i].push_back(person);
        }

        for(int j=0; j<num_party-1; j++) {
            union_party(parties[i][j], parties[i][j+1]);
        }
    }
        
    int cnt = M;
    
    int truth_parent = find_parent(0);
    for(int i=0; i<M; i++) {
        for(int j : parties[i]) {
            if(truth_parent == find_parent(j)) {
                cnt--;
                break;
            }
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}