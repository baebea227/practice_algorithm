#include <bits/stdc++.h>
using namespace std;

struct Gem {
    int weight, value;
};

bool compareGem(const Gem& a, const Gem& b) {
    return a.weight < b.weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Gem> gems(n);
    vector<int> bag(k);
    
    for(int i=0; i<n; i++) {
        cin >> gems[i].weight >> gems[i].value;
    }
    for(int i=0; i<k; i++) {
        cin >> bag[i];
    }

    sort(gems.begin(), gems.end(), compareGem);
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    long long answer = 0;
    int gemIdx = 0;

    for(int i=0; i<k; i++) {
        while(gemIdx < n && gems[gemIdx].weight <= bag[i]) {
            pq.push(gems[gemIdx].value);
            gemIdx++;
        }

        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << '\n';
}