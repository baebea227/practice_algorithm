#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char left;
    char right;
};

vector<Node> tree(26);

void preorder(char nodeChar) {
    if(nodeChar == '.') return;
    cout << nodeChar;
    preorder(tree[nodeChar - 'A'].left);
    preorder(tree[nodeChar - 'A'].right);
}

void inorder(char nodeChar) {
    if(nodeChar == '.') return;
    inorder(tree[nodeChar - 'A'].left);
    cout << nodeChar;
    inorder(tree[nodeChar - 'A'].right);
}

void postorder(char nodeChar) {
    if(nodeChar == '.') return;
    postorder(tree[nodeChar - 'A'].left);
    postorder(tree[nodeChar - 'A'].right);
    cout << nodeChar;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        tree[parent - 'A'].left = left;
        tree[parent - 'A'].right = right;
    }
    
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
}