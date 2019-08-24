class Class {};
class Base : public Class {
public:
	Base() = default;
	Base(const Base &b) {}
	Base(int i) {}
};

class D1 : virtual public Base {
public:
	D1() = default;
	D1(const D1 &d) {}
	D1(int i) : Base(i) {}
};
class D2 : virtual public Base {
public:
	D2() = default;
	D2(const D2 &d) {}
	D2(int i) : Base(i) {}
};
class MI : public D1, public D2 {
public:
	MI() = default;
	MI(const MI &d) {}
	MI(int i) : D1(i), D2(i){}
};
class Final : public MI, public Class {
public:
	Final() = default;
	Final(const Final&d) {}
	Final(int i) : MI(i){}
};