#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int getLevelingTime(vector<int> &heights, int b, int targetH) {
    int time = 0;
    for (int h : heights) {
        if (h > targetH) {
            int remove = h - targetH;
            b += remove;
            time += remove * 2;
        }
        else if (h < targetH) {
            int add = targetH - h;
            b -= add;
            time += add;
        }
    }
    if (b < 0) return INF;
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, b;
    cin >> n >> m >> b;
    
    vector<int> heights(n*m);
    int minH = 256;
    int maxH = 0;

    for (int i=0; i<n*m; i++) {
        cin >> heights[i];
        minH = min(minH, heights[i]);
        maxH = max(maxH, heights[i]);
    }

    int bestTime = INF;
    int bestHeight = -1;

    for (int h = maxH; h >= minH; h--) {
        int time = getLevelingTime(heights, b, h);
        if (time < bestTime) {
            bestTime = time;
            bestHeight = h;
        }
    }
    cout << bestTime << " " << bestHeight << '\n';
}