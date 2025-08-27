#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 5, 6, 7}; // 4 is missing
    int n = 6;
    int expectedSum = ( (arr[0] + arr[n-1]) * (n+1) ) / 2; 
    int actualSum = 0;
    for (int i = 0; i < n; i++)
        actualSum += arr[i];
    int missing = expectedSum - actualSum;
    cout << "Missing number is: " << missing << endl;
    return 0;
}
