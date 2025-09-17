#include <iostream>
using namespace std;
// (a) Diagonal Matrix
void diagonalMatrix(int n, int diag[]) {
    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
// (b) Tri-diagonal Matrix
void tridiagonalMatrix(int n, int tri[]) {
    cout << "Tridiagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j+1 || i+1 == j) cout << tri[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
// (c) Lower Triangular
void lowerTriangular(int n, int lower[]) {
    cout << "Lower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) cout << lower[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
// (d) Upper Triangular
void upperTriangular(int n, int upper[]) {
    cout << "Upper Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) cout << upper[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
// (e) Symmetric Matrix
void symmetricMatrix(int n, int sym[]) {
    cout << "Symmetric Matrix:\n";
    int k = 0;
    int full[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            full[i][j] = sym[k];
            full[j][i] = sym[k];
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << full[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int diag[3] = {1,2,3};
    diagonalMatrix(3, diag);
    int tri[7] = {1,2,3,4,5,6,7};
    tridiagonalMatrix(3, tri);
    int lower[6] = {1,2,3,4,5,6};
    lowerTriangular(3, lower);
    int upper[6] = {1,2,3,4,5,6};
    upperTriangular(3, upper);
    int sym[6] = {1,2,3,4,5,6};
    symmetricMatrix(3, sym);
    return 0;
}
