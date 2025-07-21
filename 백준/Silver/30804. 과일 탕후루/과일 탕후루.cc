#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    int left = 0, result = 1;
    unordered_map<int, int> freq;
    for(int right=0; right<n; right++) {
        freq[v[right]]++;

        while(freq.size() > 2) {
            freq[v[left]]--;
            if(freq[v[left]] == 0) freq.erase(v[left]);
            left++;
        }

        result = max(result, right - left + 1);
    }

    cout << result << '\n';
}