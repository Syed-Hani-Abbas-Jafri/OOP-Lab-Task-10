#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream secret("secret.txt");
    if (!secret) {
        cerr << "Error: Could not open secret.txt." << endl;
        return 1;
    }

    int uppercaseCount = 0;
    char ch;

    while (secret.get(ch)) {
        if (isupper(ch)) {
            uppercaseCount++;
        }
    }

    secret.close();

    cout << "Signal Scan Result" << endl;
    cout << "Total uppercase signal letters found: " << uppercaseCount << endl;
    return 0;
}
