#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    char name[50];
    int  id;
    float gpa;
};

int main() {
    int n;
    cout << "=== Student GPA Record System ===" << endl;
    cout << "How many students to register? ";
    cin >> n;
    cin.ignore();

    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cerr << "Error: Could not open students.dat for writing." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "\nStudent " << (i + 1) << endl;
        cout << "  Name : ";
        cin.getline(s.name, 50);
        cout << "  ID   : ";
        cin >> s.id;
        cout << "  GPA  : ";
        cin >> s.gpa;
        cin.ignore();

        outFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }
    outFile.close();
    cout << "\nData written to students.dat" << endl;

    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open students.dat for reading." << endl;
        return 1;
    }

    cout << "\n=== Stored Student Records ===" << endl;
    cout << "------------------------------------" << endl;

    Student s;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "Name : " << s.name << endl;
        cout << "ID   : " << s.id   << endl;
        cout << "GPA  : " << s.gpa  << endl;
        cout << "------------------------------------" << endl;
    }

    inFile.close();
    return 0;
}
