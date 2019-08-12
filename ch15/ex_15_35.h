#ifndef EX_15_35_H
#define EX_15_35_H

#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <map>
#include <set>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::set;
using std::map;
using std::shared_ptr;
using std::getline;


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
    friend std::ostream& print(std::ostream &os, const QueryResult &qr);
public:
	using line_no = vector<string>::size_type;
    QueryResult(string s,
                                shared_ptr<set<line_no>> p,
                                shared_ptr<vector<string>> f):
                            sought(s), lines(p), file(f) {}
private:
    string sought;
    shared_ptr<vector<string>> file;
    shared_ptr<set<line_no>> lines;
};

QueryResult TextQuery::query(const string &s) const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(s);
    if (loc == wm.end())
        return QueryResult(s, nodata, file);
    return QueryResult(s, loc->second, file);
}
class Query;
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string &);
	QueryResult eval(const TextQuery &t);
	string rep() const {
		cout << "Query::rep()" << endl;
		return q->rep();
	}
private:
	Query(shared_ptr<Query_base> query): q(query) {
		cout << "Query(shared_ptr<Query_base> query)" << endl;
	}
	shared_ptr<Query_base> q;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query) {
	return os << query.rep();
}
#endif