/**
	Query_base 为抽象基类，其派生类构造函数都为private。现在暂且用一个简单模型代替。
*/
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
class Query_base {
public:
	virtual ~Query_base(){}
};
class BinaryQuery : public Query_base {
public:
	virtual ~BinaryQuery(){}
};
class AndQuery : public BinaryQuery {
public:
	virtual ~AndQuery(){}
};
class OrQuery : public BinaryQuery {
public:
	virtual ~OrQuery(){}
};
class NotQuery : public Query_base {
public:
	virtual ~NotQuery(){}
};

int main()
{
	// 19.6
	Query_base *qb1 = new AndQuery;
	Query_base *qb2 = new NotQuery;
	if (AndQuery *aq = dynamic_cast<AndQuery*>(qb1))
		cout << "succeed" << endl;
	else
		cout << "fail" << endl;
	if (AndQuery *aq = dynamic_cast<AndQuery*>(qb2))
		cout << "succeed" << endl;
	else
		cout << "fail" << endl;
	// 19.7
	AndQuery a;
	NotQuery n;
	Query_base &rq1 = a;
	Query_base &rq2 = n;
	try {
		AndQuery &aq = dynamic_cast<AndQuery&>(rq1);
		cout << "succeed" << endl;
	} catch (std::bad_cast) {
		cout << "fail" << endl;
	}
	try {
		AndQuery &aq = dynamic_cast<AndQuery&>(rq2);
		cout << "succeed" << endl;
	} catch (std::bad_cast) {
		cout << "fail" << endl;
	}
	// 19.8
	if (typeid(rq1) == typeid(rq2))
		cout << "the same type" << endl;
	else
		cout << "different type" << endl;
	if (typeid(rq1) == typeid(AndQuery))
		cout << "the type is AndQuery" << endl;
	else
		cout << "unknown type" << endl;
	return 0;
}