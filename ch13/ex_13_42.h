#ifndef EX_12_30_H
#define EX_12_30_H

#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <map>
#include <set>
#include "ex_13_39.h"
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;
using std::shared_ptr;
using std::getline;

using line_no = size_t;
class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &is);
    QueryResult query(const string &s) const;
private:
    shared_ptr<StrVec> file;
    map<string, 
        shared_ptr<set<line_no>>> wm;
};

class QueryResult {
    friend std::ostream& print(std::ostream &os, const QueryResult &qr);
public:
    QueryResult(string s,
                                shared_ptr<set<line_no>> p,
                                shared_ptr<StrVec> f):
                            sought(s), lines(p), file(f) {}
private:
    string sought;
    shared_ptr<StrVec> file;
    shared_ptr<set<line_no>> lines;
};
// std::ostream& print(std::ostream &os, const QueryResult &qr);
#endif