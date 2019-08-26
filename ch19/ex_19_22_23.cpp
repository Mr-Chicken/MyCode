#include "../ch08/Sales_data.h"

#include <string>
using std::string;

class Token {
public:
	Token(): tok(INT), ival{0} {}
	Token(const Token &t): tok(t.tok) {copyUnion(t);}
	Token(Token &&t) noexcept : tok(t.tok){
		switch (t.tok) {
			case INT : ival = t.ival; break;
			case CHAR: cval = t.cval; break;
			case DBL : dval = t.dval; break;
			case STR : sval = t.sval; break;
			case SALE: sale = t.sale; break;
		}
	}
	Token& operator=(Token &&t) noexcept;
	Token& operator=(const Token&t);
	~Token() {
		if (tok == STR) sval.~string();
		if (tok == SALE) sale.~Sales_data();
	}
	Token& operator=(const string &);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(const Sales_data &sd);
	Token& operator=(double);
private:
	enum {INT, CHAR, DBL, STR, SALE} tok;
	union {
		char cval;
		int ival;
		double dval;
		string sval;
		Sales_data sale;
	};
	void copyUnion(const Token &);
};
Token& Token::operator=(Token &&t) noexcept{
	if (this != &t) {
		this->~Token();
		copyUnion(t);
		tok = std::move(tok);
	}
	return *this;

}
Token& Token::operator=(const Sales_data &sd) {
	if (tok == STR) sval.~string();
	if (tok == SALE)
		sale = sd;
	else
		new(&sale) Sales_data(sd);
	tok = SALE;
	return *this;
}
Token& Token::operator=(const string &s) {
	if (tok == SALE) sale.~Sales_data();
	if (tok == STR)
		sval = s;
	else
		new(&sval) string(s);
	tok = STR;
	return *this;
}
Token& Token::operator=(int i) {
	if (tok == STR) sval.~string();
	if (tok == SALE) sale.~Sales_data();
	ival = i;
	tok = INT;
	return *this;
}
Token& Token::operator=(char c) {
	if (tok == STR) sval.~string();
	if (tok == SALE) sale.~Sales_data();
	cval = c;
	tok = CHAR;
	return *this;
}
Token& Token::operator=(double d) {
	if (tok == STR) sval.~string();
	if (tok == SALE) sale.~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
}
void Token::copyUnion(const Token &t) {
	switch (t.tok) {
		case Token::INT : ival = t.ival; break;
		case Token::CHAR: cval = t.cval; break;
		case Token::DBL : dval = t.dval; break;
		case Token::STR : new(&sval) string(t.sval); break;
		case Token::SALE: new(&sale) Sales_data(t.sale); break;
	}
}
Token& Token::operator=(const Token &t) {
	if (tok == SALE && t.tok != SALE) sale.~Sales_data();
	else if (tok == SALE && t.tok == SALE)
		sale = t.sale;
	else if (tok == STR && t.tok != STR) sval.~string();
	else if (tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}