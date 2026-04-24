#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Backup Logger" << endl;
    cout << "Enter log message (exit to stop):" << endl;

    ofstream logFile("backup_log.txt", ios::app);
    if (!logFile) {
        cerr << "Error: Could not open backup_log.txt." << endl;
        return 1;
    }

    string message;
    while (true) {
        cout << "\nLog message: ";
        getline(cin, message);

        if (message == "exit") break;

        logFile << message << "\n";
        logFile.flush();

        streampos currentSize = logFile.tellp();
        cout << "Entry saved. Current file size: " << currentSize << " bytes." << endl;
    }

    logFile.close();
    cout << "Backup log closed." << endl;
    return 0;
}
