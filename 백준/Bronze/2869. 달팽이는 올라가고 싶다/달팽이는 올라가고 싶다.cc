#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, v;
    cin >> a >> b >> v;
    
    int day = (v-a)/(a-b)+2;
    if ((v-a)%(a-b)==0) day--;

    cout << day << '\n';
}