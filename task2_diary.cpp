#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;

    cout << "=== Personal Diary ===" << endl;
    cout << "Type your diary entries (type 'exit' to stop):" << endl;

    ofstream diary("diary.txt", ios::app);
    if (!diary) {
        cerr << "Error: Could not open diary.txt." << endl;
        return 1;
    }

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line == "exit") break;

        diary << line << "\n";
    }

    diary.close();
    cout << "Diary saved successfully!" << endl;
    return 0;
}
