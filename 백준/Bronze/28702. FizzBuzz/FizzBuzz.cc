#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string n;
    int num;
    for (int i=0; i<3; i++) {
        cin >> n;
        (n == "FizzBuzz" || n == "Fizz" || n == "Buzz") ? num++ : num = stoi(n)+1;
    }

    (num % 15 == 0) ? cout << "FizzBuzz" << '\n' :
    (num % 3 == 0) ? cout << "Fizz" << '\n' :
    (num % 5 == 0) ? cout << "Buzz" << '\n' :
    cout << num << '\n';
}