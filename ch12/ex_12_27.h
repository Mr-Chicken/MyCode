#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using std::vector;
using std::set;
using std::map;
using std::string;
using std::shared_ptr;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::cout;
using std::make_shared;
using std::endl;
using std::getline;
class QueryResult;
class TextQuery {
public: 
   using lineNo = vector<string>::size_type;
   TextQuery(ifstream &infile);
   QueryResult query(const string &word);
private:
    shared_ptr<vector<string>> lines;
    map<string, shared_ptr<set<lineNo>>> mp;
};

class QueryResult {
    friend ostream& print(ostream& os, const QueryResult &qr);
public:
    using lineNo = vector<string>::size_type;
    QueryResult(const string &s, shared_ptr<vector<string>> ls, shared_ptr<set<lineNo>> num)
        : word(s), lines(ls), wdline(num) {}
private:
    string word;
    shared_ptr<vector<string>> lines;
    shared_ptr<set<lineNo>> wdline;
};