#include "ex_12_27.h"

ostream& print(ostream& os, const QueryResult &qr) {
    cout << qr.word << " occurs " << qr.wdline->size() << " times" << endl;
    for (auto it = qr.wdline->begin(), end = qr.wdline->end(); it != end; ++it) {
        cout << "\t" << "(line " << *it << ") "
            << (*qr.lines)[*it - 1] << endl; // 取角标
    }
    return os;
}

TextQuery::TextQuery(ifstream &infile) {
    // 给容器初始化
    lines = make_shared<vector<string>>();
    string line;
    for (int num = 1; getline(infile, line); ++num) {
        lines->push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (mp[word]) { // 假如指针初始化了
                mp[word]->insert(num);
            } else { // 还没初始化
                mp[word] = make_shared<set<lineNo>>();
                mp[word]->insert(num);
            }
        }
    }
}
QueryResult TextQuery::query(const string &word) {
    QueryResult qr(word, lines, mp.find(word)->second);
    return qr;
}