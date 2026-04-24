#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream draft("draft.txt", ios::in | ios::out);
    if (!draft) {
        cerr << "Error: Could not open draft.txt." << endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(draft)),
                    istreambuf_iterator<char>());

    size_t pos = content.find("teh");
    if (pos == string::npos) {
        cout << "No occurrence of 'teh' found." << endl;
        draft.close();
        return 0;
    }

    cout << "Found 'teh' at byte offset: " << pos << endl;

    draft.seekp(pos, ios::beg);
    draft.write("the", 3);
    draft.flush();

    cout << "Fixed: 'teh' -> 'the' at position " << pos << endl;
    cout << "File structure remains intact." << endl;

    draft.close();
    return 0;
}
