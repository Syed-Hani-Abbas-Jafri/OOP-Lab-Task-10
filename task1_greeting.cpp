#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, message;

    cout << "=== Greeting Card Generator ===" << endl;
    cout << "Enter recipient's name: ";
    getline(cin, name);
    cout << "Enter your message: ";
    getline(cin, message);

    ofstream file("greeting.txt");
    if (!file) {
        cerr << "Error: Could not open greeting.txt for writing." << endl;
        return 1;
    }

    file << "Dear " << name << "," << endl;
    file << message << endl;
    file << "Best Regards!" << endl;

    file.close();
    cout << "\ngreeting.txt created successfully!" << endl;
    return 0;
}
