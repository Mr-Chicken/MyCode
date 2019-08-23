#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <memory>
using std::shared_ptr;
using std::vector;
using std::string;
using std::set;
using std::map;

namespace chapter15 {
	class QueryResult;
	class TextQuery {
	public:
		using line_no = vector<string>::size_type;
	    TextQuery(std::ifstream &is);
	    QueryResult query(const string &s) const;
	private:
	    shared_ptr<vector<string>> file;
	    map<string, 
        shared_ptr<set<line_no>>> wm;
	};
	class QueryResult {
    	friend std::ostream& operator<<(std::ostream &os, const QueryResult &qr);
	public:
		using line_no = vector<string>::size_type;
    	QueryResult(string s,
                            shared_ptr<set<line_no>> p,
                            shared_ptr<vector<string>> f):
                            sought(s), lines(p), file(f) {}
    	set<line_no>::iterator begin() {return lines->begin();}
    	set<line_no>::iterator end() {return lines->end();}
    	shared_ptr<vector<string>> get_file() const{return file;}
	private:
    	string sought;
    	shared_ptr<vector<string>> file;
    	shared_ptr<set<line_no>> lines;
	};
}