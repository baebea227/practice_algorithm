#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr1;
vector<int> arr2;
vector<int> sortedArr;
vector<int> answer; 

int findMax(int curMax, int &i, int &j) {
    int ii = i, jj =j;
    while(ii < N) {
        if(arr1[ii] == curMax) {
            while(jj < M) {
                if(arr2[jj] == curMax) {
                    i = ii + 1;
                    j = jj + 1;
                    return curMax;
                }
                jj++;
            }
        }
        ii++;
    }
    return -1;
}

void solve() {

    cin >> N;
    arr1.resize(N);
    for(int i=0; i<N; i++) cin >> arr1[i];

    cin >> M;
    arr2.resize(M);
    for(int i=0; i<M; i++) cin >> arr2[i];

    sortedArr.resize(N);
    for(int i=0; i<N; i++) sortedArr[i] = arr1[i];
    sort(sortedArr.begin(), sortedArr.end(), greater<int>());

    int i=0, j=0;
    for(int curMax : sortedArr) {
        int num = findMax(curMax, i, j);
        if(num != -1) answer.push_back(num);
    }

    cout << answer.size() << '\n';
    for(int i : answer) cout << i << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}