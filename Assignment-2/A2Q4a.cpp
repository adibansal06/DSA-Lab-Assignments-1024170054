#include <iostream>
using namespace std;
int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    int i = 0, j = 0;
    while (str1[i] != '\0') i++;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}
