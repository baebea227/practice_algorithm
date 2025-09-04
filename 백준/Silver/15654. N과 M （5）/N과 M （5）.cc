#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> seq;
vector<int> nums;
vector<bool> used;
int N, M;

void backtrack(int depth) {
    if(depth == M) {
        for(int i : seq) cout << i << " ";
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++) {
        if(used[i]) continue;
        seq.push_back(nums[i]);
        used[i] = true;
        backtrack(depth+1);
        seq.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    nums.resize(N);
    used.resize(N);
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    backtrack(0);
}