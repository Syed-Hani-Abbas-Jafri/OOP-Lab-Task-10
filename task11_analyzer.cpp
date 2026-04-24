#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream article("article.txt");
    if (!article) {
        cerr << "Error: Could not open article.txt." << endl;
        return 1;
    }

    long totalChars = 0, totalWords = 0, totalLines = 0, totalPunct = 0;
    string line;
    string punctMarks = ".,;:!?\"'-()[]{}";

    while (getline(article, line)) {
        totalLines++;
        totalChars += line.length();

        istringstream iss(line);
        string word;
        while (iss >> word) totalWords++;

        for (char ch : line) {
            if (punctMarks.find(ch) != string::npos) totalPunct++;
        }
    }
    article.close();

    ofstream report("report.txt");
    if (!report) {
        cerr << "Error: Could not create report.txt." << endl;
        return 1;
    }

    report << "========================================\n";
    report << "      CONTENT QUALITY ANALYSIS REPORT   \n";
    report << "========================================\n\n";
    report << "Total Characters    : " << totalChars << "\n";
    report << "Total Words         : " << totalWords << "\n";
    report << "Total Lines         : " << totalLines << "\n";
    report << "Punctuation Marks   : " << totalPunct << "\n";
    report << "\n========================================\n";
    report.close();

    cout << "=== Analysis Complete ===" << endl;
    cout << "Characters  : " << totalChars << endl;
    cout << "Words       : " << totalWords << endl;
    cout << "Lines       : " << totalLines << endl;
    cout << "Punctuation : " << totalPunct << endl;
    cout << "Results saved to report.txt" << endl;

    return 0;
}
