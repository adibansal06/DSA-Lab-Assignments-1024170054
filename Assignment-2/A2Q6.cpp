#include <iostream>
using namespace std;
const int MAX = 100;
void printSparse(int triplet[][3], int nonZero) {
    cout << "Row Col Val\n";
    for (int i = 0; i < nonZero; i++) {
        cout<<triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }
}
// (a) Transpose
void transpose(int triplet[][3], int nonZero) {
    for (int i = 0; i < nonZero; i++) {
        int temp = triplet[i][0];
        triplet[i][0] = triplet[i][1];
        triplet[i][1] = temp;
    }
    cout<<"Transpose:\n";
    printSparse(triplet, nonZero);
}
// (b) Addition
void addSparse(int A[][3], int a, int B[][3], int b) {
    int C[MAX][3];
    int i=0, j=0, k=0;
    while(i<a && j<b) {
        if(A[i][0]==B[j][0] && A[i][1]==B[j][1]) {
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2]+B[j][2];
            i++; j++; k++;
        } else if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++;
        } else {
            C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++;
        }
    }
    while(i<a){
        C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++;
    }
    while(j<b){
        C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++;
    }
    cout<<"Addition:\n";
    printSparse(C,k);
}
// (c) Multiplication 
void multiplySparse(int A[][3], int a, int B[][3], int b, int rows, int cols) {
    int result[MAX][3], k=0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (A[i][1] == B[j][0]) {
                result[k][0] = A[i][0];
                result[k][1] = B[j][1];
                result[k][2] = A[i][2] * B[j][2];
                k++;
            }
        }
    }
    cout<<"Multiplication:\n";
    printSparse(result, k);
}
int main() {
    int A[3][3] = {{0,5,0}, {0,0,3}, {2,0,0}};
    int tripletA[MAX][3];
    int nonZeroA = 0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(A[i][j]!=0) {
                tripletA[nonZeroA][0]=i;
                tripletA[nonZeroA][1]=j;
                tripletA[nonZeroA][2]=A[i][j];
                nonZeroA++;
            }
        }
    }
    cout << "Original Sparse Matrix:\n";
    printSparse(tripletA, nonZeroA);
    transpose(tripletA, nonZeroA);
    // For addition, just re-use two arrays A and A itself
    addSparse(tripletA, nonZeroA, tripletA, nonZeroA);
    // Multiplication with itself
    multiplySparse(tripletA, nonZeroA, tripletA, nonZeroA, 3, 3);
    return 0;
}
