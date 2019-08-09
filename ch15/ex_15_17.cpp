#include "ex_15_16.h"

int main()
{
	Disc_quote dq;
	/*
		ex_15_17.cpp:5:13: error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
  	Disc_quote dq;
  	
  		ex_15_16.h:4:7: note:   because the following virtual functions are pure within ‘Disc_quote’:
 	class Disc_quote : public Quote {
       	  ^~~~~~~~~~
	ex_15_16.h:9:9: note: 	virtual double Disc_quote::net_price(std::size_t) const
  	double net_price(std::size_t cnt) const = 0;
	*/

	return 0;
}