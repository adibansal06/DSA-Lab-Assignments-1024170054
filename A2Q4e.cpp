#include <iostream>
using namespace std;
int main() {
    char str[50] = "HELLO WORLD";
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32; 
        i++;
    }
    cout << "Lowercase string: " << str << endl;
    return 0;
}
