struct Sale_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	Sale_data& combine(const Sale_data &rhs);
	string isbn() const {return bookNo;};
};