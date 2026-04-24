#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("article.txt");
    if (!file) {
        cerr << "Error: Could not open article.txt." << endl;
        return 1;
    }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    cout << "=== File Debugger ===" << endl;
    cout << "File size: " << fileSize << " bytes" << endl;

    string cmd;
    while (true) {
        cout << "\nEnter byte offset (or 'quit' to exit): ";
        getline(cin, cmd);

        if (cmd == "quit" || cmd == "q") break;

        long offset;
        try {
            offset = stol(cmd);
        } catch (...) {
            cout << "Invalid offset. Enter a number." << endl;
            continue;
        }

        if (offset < 0 || offset >= fileSize) {
            cout << "Offset out of range (0 to " << (long)fileSize - 1 << ")." << endl;
            continue;
        }

        file.seekg(offset, ios::beg);
        streampos posBefore = file.tellg();
        cout << "Pointer position BEFORE read: " << posBefore << endl;

        char buffer[101] = {};
        file.read(buffer, 100);
        int bytesRead = file.gcount();

        streampos posAfter = file.tellg();
        cout << "Pointer position AFTER  read: " << posAfter << endl;
        cout << "Bytes read: " << bytesRead << endl;
        cout << "--- Content ---" << endl;
        cout.write(buffer, bytesRead);
        cout << "\n--- End ---" << endl;

        file.clear();
    }

    file.close();
    cout << "Debugger closed." << endl;
    return 0;
}
