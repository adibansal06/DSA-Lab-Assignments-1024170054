#include <iostream>
using namespace std;

const int MAX = 200;
int arr[MAX], n = 0;
bool created = false; // To check if array is created

void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    created = true;
}

void displayArray() {
    if (!created) {
        cout << "Please create the array first!\n";
        return;
    }
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insertElement() {
    if (!created) {
        cout << "Please create the array first!\n";
        return;
    }
    int pos, val;
    cout << "Enter index to insert (0 to " << n << "): ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Invalid index!\n";
        return;
    }
    cout << "Enter value: ";
    cin >> val;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deleteElement() {
    if (!created) {
        cout << "Please create the array first!\n";
        return;
    }
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    int pos;
    cout << "Enter index to delete (0 to " << n - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid index!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void linearSearch() {
    if (!created) {
        cout << "Please create the array first!\n";
        return;
    }
    int key, found = 0;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i << endl;
            found = 1;
        }
    }
    if (!found) cout << "Not found\n";
}

int main() {
    int choice;
    do {
        cout << "\n========== ARRAY MENU ==========\n";
        cout << "1. Create Array\n2. Display Array\n3. Insert Element\n4. Delete Element\n5. Linear Search\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 6);
}
