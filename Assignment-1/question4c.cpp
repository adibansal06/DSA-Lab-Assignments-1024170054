#include <iostream>
using namespace std;
int main() {
    int mat[10][10], trans[10][10], rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter matrix elements:"<<endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];
    // Transpose logic
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans[j][i] = mat[i][j];
    cout << "Transpose of the matrix:"<<endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
