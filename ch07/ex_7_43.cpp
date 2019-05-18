class NoDefault {
public:
    NoDefault(int i);
};

class C {
public:
    C():mem(0) {}
private:
    NoDefault mem;
};
