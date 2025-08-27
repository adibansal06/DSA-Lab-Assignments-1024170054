#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 2, 1, 4, 5};
    int n = 7;
    int distinct = 0;
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) distinct++;
    }
    cout << "Total distinct elements = " << distinct << endl;
    return 0;
}
