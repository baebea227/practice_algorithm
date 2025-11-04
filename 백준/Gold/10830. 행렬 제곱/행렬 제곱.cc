#include <iostream>
#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix matMul(const Matrix &a, const Matrix &b, int N) {
    Matrix temp(N, vector<int>(N, 0));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++)
                temp[i][j] += a[i][k] * b[k][j];
            temp[i][j] %= 1000;
        }
    }

    return temp;
}

Matrix matPow(long long n, const Matrix &mat, int N) {
    if(n == 1)
        return mat;

    Matrix half = matPow(n/2, mat, N);
    Matrix squared = matMul(half, half, N);

    if(n % 2 == 0)
        return squared;
    else
        return matMul(mat, squared, N);
}

void solve() {
    int N;
    long long B;
    cin >> N >> B;

    Matrix mat(N, vector<int>(N));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> mat[i][j];
            mat[i][j] %= 1000;
        }
    }

    Matrix result = matPow(B, mat, N);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}