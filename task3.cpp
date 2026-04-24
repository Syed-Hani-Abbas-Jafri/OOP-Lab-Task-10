#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, email, choice;

    cout << "Workshop Registration" << endl;

    ofstream signup("signup.txt", ios::app);
    if (!signup) {
        cerr << "Error: Could not open signup.txt." << endl;
        return 1;
    }

    do {
        cout << "\nEnter name: ";
        getline(cin, name);
        cout << "Enter email: ";
        getline(cin, email);

        signup << "Name: " << name << ", Email: " << email << "\n";
        cout << "Registration saved!" << endl;

        cout << "Register another user? (yes/no): ";
        getline(cin, choice);
    } while (choice == "yes" || choice == "y");

    signup.close();
    cout << "All registrations completed." << endl;
    return 0;
}
