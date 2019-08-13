#include "ex_15_35.h"

class WordQuery : public Query_base{
	friend class Query;
	WordQuery(const string &s):query_word(s) {
		cout << "WordQuery(const string &s)" << endl;
	}
	QueryResult eval(const TextQuery &t) const 
		{return t.query(query_word);}
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
	QueryResult eval(const TextQuery &t) const{};
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
	QueryResult eval(const TextQuery &t) const {}
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
	QueryResult eval(const TextQuery &t) const {}
};
inline Query operator|(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q << endl;
	return 0;
}