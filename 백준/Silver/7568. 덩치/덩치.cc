#include <iostream>
using namespace std;

struct Person {
public:
    int weight;
    int height;
    int ranking = 1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    Person people[n];
    for (int i=0; i<n; i++) {
        cin >> people[i].weight >> people[i].height;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (people[i].weight < people[j].weight && people[i].height < people[j].height) people[i].ranking++;
        }
        cout << people[i].ranking << ' ';
    }
    cout << '\n';
}