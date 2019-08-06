#include <iostream>
using std::cout;
using std::endl;

class Vehicle {
	friend inline bool operator==(const Vehicle &lhs, const Vehicle &rhs);
	friend inline bool operator!=(const Vehicle &lhs, const Vehicle &rhs);
	friend inline bool operator<(const Vehicle &lhs, const Vehicle &rhs);
	friend inline bool operator>(const Vehicle &lhs, const Vehicle &rhs);
	friend inline bool operator<=(const Vehicle &lhs, const Vehicle &rhs);
	friend inline bool operator>=(const Vehicle &lhs, const Vehicle &rhs);
public:
	Vehicle(unsigned v = 0, unsigned o = 0): velocity(v), oil(o) {}
	Vehicle(const Vehicle &ve);
	Vehicle& operator=(const Vehicle &rhs);
	Vehicle& operator=(Vehicle &&ve) noexcept;
	explicit operator bool() const {
		return velocity;
	}
private:
	unsigned velocity;
	unsigned oil;
};
Vehicle::Vehicle(const Vehicle &ve): velocity(ve.velocity), oil(ve.oil) {}
Vehicle& Vehicle::operator=(const Vehicle &rhs) {
	if (this != &rhs) {
		velocity = rhs.velocity;
		oil = rhs.oil;
	}
	return *this;
}
Vehicle& Vehicle::operator=(Vehicle &&ve) noexcept {
	if (this != &ve) {
		velocity = ve.velocity;
		oil = ve.oil;
	}
	return *this;
}
inline bool operator==(const Vehicle &lhs, const Vehicle &rhs) {
	return lhs.velocity == rhs.velocity && lhs.oil == rhs.oil;
}
inline bool operator!=(const Vehicle &lhs, const Vehicle &rhs) {
	return !(lhs == rhs);
}
inline bool operator<(const Vehicle &lhs, const Vehicle &rhs) {
	return lhs.velocity < rhs.velocity && lhs.oil < rhs.oil;
}
inline bool operator>(const Vehicle &lhs, const Vehicle &rhs) {
	return rhs < lhs;
}
inline bool operator<=(const Vehicle &lhs, const Vehicle &rhs) {
	return lhs.velocity <= rhs.velocity && lhs.oil <= rhs.oil;
}
inline bool operator>=(const Vehicle &lhs, const Vehicle &rhs) {
	return rhs <= lhs;
}
int main()
{
	Vehicle car(60, 3000);
	Vehicle bus(70, 5000);
	cout << (car < bus) << endl;
	return 0;
}