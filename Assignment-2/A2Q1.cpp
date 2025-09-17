#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int main() {
    int arr[7] = {2, 4, 7, 10, 15, 20, 25};
    int n = 7;
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    cout << "Linear Search Result: ";
    int result1 = linearSearch(arr, n, key);
    if (result1 != -1)
        cout << "Element found at index " << result1 << endl;
    else
        cout << "Not found" << endl;
    cout << "Binary Search Result: ";
    int result2 = binarySearch(arr, n, key);
    if (result2 != -1)
        cout << "Element found at index " << result2 << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
