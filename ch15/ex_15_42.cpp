#ifndef EX_15_35_H
#define EX_15_35_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
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
using std::make_shared;
using std::getline;
using std::set_intersection;

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
TextQuery::TextQuery(std::ifstream &is) : file(new vector<string>){
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}
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
	friend Query makeLimited(const Query &q, size_t low, size_t upper);
public:
	Query(const string &);
	QueryResult eval(const TextQuery &t) const {
		cout << "Query::eval(const TextQuery &t)" << endl;
		return q->eval(t);
	}
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

class WordQuery : public Query_base{
	friend class Query;
	WordQuery(const string &s):query_word(s) {
		cout << "WordQuery(const string &s)" << endl;
	}
	QueryResult eval(const TextQuery &t) const {
		cout << "WordQuery::eval(const TextQuery &t)" << endl;
		return t.query(query_word);
	}
	string rep() const {
		cout << "WordQuery::rep()" << endl;
		return query_word;
	}
	string query_word;
};
inline Query::Query(const string &s): q(new WordQuery(s)){
	cout << "Query::Query(const string &s)" << endl;
}

class NotQuery : public Query_base{
	friend Query operator~(const Query &);
	NotQuery(const Query &q): query(q) {
		cout << "NotQuery(const Query &)" << endl;
	}
	string rep() const {
		cout << "NotQuery::rep()" << endl;
		return "!(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery &t) const{
		cout << "NotQuery::eval(const TextQuery &t)" << endl;
		auto result = query.eval(t);
		auto ret_lines = make_shared<set<line_no>>();
		auto beg = result.begin(), end = result.end();
		auto sz = result.get_file()->size();
		for (size_t n = 0; n != sz; ++n) {
			if (beg == end || *beg != n)
				ret_lines->insert(n);
			else if (beg != end)
				++beg;
		}
		return QueryResult(rep(), ret_lines, result.get_file());
	}
	Query query;
};
inline Query operator~(const Query &q) {
	return shared_ptr<Query_base>(new NotQuery(q));
}
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, string s):
		lhs(l), rhs(r), opSym(s) {
			cout << "BinaryQuery(const Query &l, const Query &r, string s)" << endl;
	}
	string rep() const {
		cout << "BinaryQuery::rep()" << endl;
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	string opSym;
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right):
		BinaryQuery(left, right, "&") {
			cout << "AndQuery(const Query &left, const Query &right)" << endl;
	}
	QueryResult eval(const TextQuery &t) const {
		cout << "AndQuery::eval(const TextQuery &t)" << endl;
		auto left = lhs.eval(t), right = rhs.eval(t);
		auto ret_lines = make_shared<set<line_no>>();
		set_intersection(left.begin(), left.end(), right.begin(), right.end(), 
			inserter(*ret_lines, ret_lines->begin()));
		return QueryResult(rep(), ret_lines, left.get_file());
	};
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right):
		BinaryQuery(left, right, "|") {
			cout << "OrQuery(const Query &left, const Query &right)" << endl;
	}
	QueryResult eval(const TextQuery &t) const {
		cout << "OrQuery::eval(const TextQuery &t)" << endl;
		auto right = rhs.eval(t), left = lhs.eval(t);
		auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end()); 
		ret_lines->insert(right.begin(), right.end());
		return QueryResult(rep(), ret_lines, left.get_file());
	}
};
inline Query operator|(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline  string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1)? word + ending : word;
}
std::ostream& operator<<(std::ostream& os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() <<" "
    <<  make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num :*qr.lines) {
        os << "\t(line " << num + 1 << ") " <<  *(qr.file->begin() + num) << endl;
    }
    return os;
}
class LimitQuery : public Query_base {
	friend Query makeLimited(const Query &q, size_t low, size_t upper);
	LimitQuery(const Query &q, std::pair<size_t, size_t> lmit): query(q), limit(lmit) {}
	string rep() const {
		return "limit(" + std::to_string(limit.first) + "," + " " + std::to_string(limit.second) + ")";
	}
	QueryResult eval(const TextQuery &t) const {
		auto result = query.eval(t);
		auto ret_lines = make_shared<set<line_no>>();
		auto beg = upper_bound(result.begin(), result.end(), limit.first);
		auto end = lower_bound(result.begin(), result.end(), limit.second);
		while (beg != end)
			ret_lines->insert(*beg++);
		return QueryResult(rep(), ret_lines, result.get_file());
	}
	Query query;
	std::pair<size_t, size_t> limit;
};
Query makeLimited(const Query &q, size_t low, size_t upper) {
	return shared_ptr<Query_base>(new LimitQuery(q, {low, upper}));
}
int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	Query p = makeLimited(Query("fiery"), 3, 6);
	// cout << q << endl;
	std::ifstream file("Story.txt");
	cout << p.eval(TextQuery(file));
	return 0;
}