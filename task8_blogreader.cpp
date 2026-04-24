#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream article("article.txt");
    if (!article) {
        cerr << "Error: Could not open article.txt." << endl;
        return 1;
    }

    article.seekg(0, ios::end);
    streampos fileSize = article.tellg();
    streampos midPoint = fileSize / 2;
    article.seekg(midPoint, ios::beg);

    string partialLine;
    getline(article, partialLine);

    cout << "=== Article Preview (from midpoint) ===" << endl;
    cout << "File size : " << fileSize << " bytes" << endl;
    cout << "Midpoint  : byte " << midPoint << endl;
    cout << "----------------------------------------" << endl;

    string line;
    int lineCount = 0;
    while (lineCount < 10 && getline(article, line)) {
        cout << line << "\n";
        lineCount++;
    }

    article.close();
    return 0;
}
