#include <iostream>
using namespace std;

void solve() {
    string str, bomb;
    cin >> str >> bomb;

    int bomb_len = bomb.size();
    string answer = "";

    for(char c : str) {
        answer += c;
        if(c == bomb.back() && answer.size() >= bomb_len) {
            if(answer.substr(answer.size() - bomb_len, bomb_len) == bomb) {
                answer.erase(answer.size() - bomb_len, bomb_len);
            }
        }
    }

    if(answer.empty()) cout << "FRULA" << '\n';
    else cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}