#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

int main() {
    time_t now = time(nullptr);
    string timestamp = ctime(&now);
    if (!timestamp.empty() && timestamp.back() == '\n')
        timestamp.pop_back();

    ofstream logFile("system_log.txt", ios::app);
    if (!logFile) {
        cerr << "Error: Could not open system_log.txt." << endl;
        return 1;
    }

    logFile << "System started at: " << timestamp << "\n";
    logFile.close();

    cout << "Log entry added: System started at: " << timestamp << endl;
    return 0;
}
