#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;
map<int, int> nums;
vector<int> seq;

void backtrack(int depth) {
    if(depth == M) {
        for(int i : seq) cout << i << " ";
        cout << '\n';
        return;
    }
    
    for(auto& [num, count] : nums) {
        if(count > 0) {
            seq.push_back(num);
            nums[num]--;
            backtrack(depth+1);
            seq.pop_back();
            nums[num]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        nums[n]++;
    }

    backtrack(0);
}