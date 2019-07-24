#ifndef EX_12_30_H
#define EX_12_30_H
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::map;
using std::shared_ptr;
using std::getline;

using line_no = vector<string>::size_type;
class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &is);
    QueryResult query(const string &s) const;
private:
    shared_ptr<vector<string>> file;
    map<string, 
        shared_ptr<set<line_no>>> wm;
};

class QueryResult {
    friend std::ostream& print(std::ostream &os, const QueryResult &qr);
public:
    QueryResult(string s,
                    shared_ptr<set<line_no>> p,
                    shared_ptr<vector<string>> f):
                    sought(s), lines(p), file(f) {}
    set<line_no>::iterator begin() {return lines->begin();}
    set<line_no>::iterator end() {return lines->end();}
    shared_ptr<vector<string>> get_file() {return file;}
private:
    string sought;
    shared_ptr<vector<string>> file;
    shared_ptr<set<line_no>> lines;
};
// std::ostream& print(std::ostream &os, const QueryResult &qr);
#endif