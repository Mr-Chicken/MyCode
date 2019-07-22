#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using std::vector;
using std::set;
using std::map;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::cout;
using std::endl;
using std::getline;

using lineNo = vector<string>::size_type;
void read(ifstream &infile, vector<string> &lines, map<string, set<lineNo>> &mp) {
    string line;
    for (int num = 1; getline(infile, line); ++num) {
        lines.push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word) {
            mp[word].insert(num);
        }
    }
}
void print(const string &queryWord, const vector<string> &lines, set<lineNo> &st) {
    cout << queryWord << " occurs " << st.size() << " times" << endl;
    for (const auto &x : st) 
        cout << "\t(line " << x << ") " << lines[x - 1] << endl;
}
int main() {
    vector<string> lines;
    map<string, set<lineNo>> mp;
    ifstream infile("infile");
    read(infile, lines, mp);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(s, lines, mp.find(s)->second);
    }
    return 0;
}