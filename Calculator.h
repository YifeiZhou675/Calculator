#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Operator.h"
#include "Stack.h"
#include <memory>
using std::unique_ptr;
using std::make_unique;

class Calculator{
private:
    Stack<double> m_num;
    Stack<unique_ptr<Operator>> m_opr;
    uint32_t m_numOprdNeed; 

    double readNum(string::const_iterator &it) noexcept;
    double readNum_chk(string::const_iterator &it);
    string readFun(string::const_iterator &it) noexcept;
    unique_ptr<Operator> readOpr(string::const_iterator &it) noexcept;
    unique_ptr<Operator> readOpr_chk(string::const_iterator &it);
    bool isNum(string::const_iterator &c) noexcept {
        return (*c >= '0' && *c <= '9') || *c == '.' || *c == 'p'
                || *c == 'i';
    }
    bool isLetter(string::const_iterator &c) noexcept {
        return *c >= 'a' && *c <= 'z';
    }
    void calculate();
    void calculate_chk();
    void expr_check(string &expr);
    void remove_space(string &expr);

public:
    Calculator() {m_opr.push(make_unique<Hash>());}
    double doIt(string &expr);
};

#endif // CALCULATOR_H
