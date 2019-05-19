#include <string>

class Account {
public:
    void calculate() {amount += amount * interestRate;}
    static double rate() {return interestRate;}
    static void rate(double d);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

double Account::interestRate = initRate();
double Account::initRate() {
    return 0;
}
void Account::rate(double d) {
    interestRate = d;
}
