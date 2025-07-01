#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    for (int tc=0; tc<t; tc++) {
        string p;
        int n;
        string x;
        cin >> p >> n >> x;

        deque<int> dq;
        bool isError = false;

        for(int i=1; i<x.length()-1; i++) {
            string tmp = "";
            do {
                tmp += x[i];
                i++;
            } while(x[i] != ',' && x[i] != ']');

            dq.push_back(stoi(tmp));
        }

        bool isReversed = false;
        for(int i=0; i<p.length(); i++) {
            if(p[i] == 'R') {
                if(isReversed) isReversed = false;
                else isReversed = true;
            }
            else if(p[i] == 'D') {
                if(dq.empty()) {
                    isError = true;
                    break;
                }
                else if(isReversed) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }
        if(isReversed) {
            reverse(dq.begin(), dq.end());
        }
        if(isError) {
            cout << "error" << '\n';
        }
        else {
            cout << '[';
            if(!dq.empty()) {
                for(auto it = dq.begin(); it != dq.end() - 1; it++) {
                    cout << *it << ',';
                }
                cout << dq.back();
            }
            cout << ']' << '\n';
        }
    }
}