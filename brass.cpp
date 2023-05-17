// 银行class methods
#include "brass.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

using foramt = std::ios_base::fmtflags;
using precis = std::streamsize;
foramt setFormat();
void restore(foramt f, precis p);

Brass::Brass(const std::string& s, long an, double bal) {
    fullName = s;
    accoutNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if (amt < 0) {
        cout << "Negatice deposit\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    foramt initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0) {
        cout << "Negatice withdraw\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "withdraw amount of $" << amt << " exceeds your balance\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    foramt initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << accoutNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const std::string& s, long an, double bal, double ml, double r)
    : Brass(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r)
    : Brass(ba) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const {
    foramt initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    foramt initialState = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded\n";
    }
    restore(initialState, prec);
}

foramt setFormat() {
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

// 重置格式和精度
void restore(foramt f, precis p) {
    cout.setf(f, std::ios_base::floatfield);  // 设置流的格式，与原有格式合并。
    cout.precision(p);                        // 设置读取浮点数的精度
}