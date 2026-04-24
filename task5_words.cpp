#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream story("story.txt");
    if (!story) {
        cerr << "Error: Could not open story.txt." << endl;
        return 1;
    }

    cout << "=== Words in Story ===" << endl;

    string line, word;
    while (getline(story, line)) {
        istringstream iss(line);
        while (iss >> word) {
            cout << word << "\n";
        }
    }

    story.close();
    return 0;
}
