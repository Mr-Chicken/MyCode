#include <exception>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::exception;
using std::bad_cast;
using std::bad_alloc;
using std::runtime_error;
using std::logic_error;
using std::overflow_error;
using std::domain_error;
using std::underflow_error;
using std::range_error;
using std::invalid_argument;
using std::out_of_range;
using std::length_error;

int main()
{
	try {

	}
	catch (const range_error &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const underflow_error &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const overflow_error &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const runtime_error &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const length_error &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const invalid_argument &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const domain_error &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const out_of_range &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const logic_error &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const bad_alloc &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const bad_cast &r) {
		cout << r.what() << endl;
		abort();
	}
	catch (const exception &r) {
		cout << r.what() << endl;
		abort();
	}
	return 0;
}