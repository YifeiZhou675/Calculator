#include "Calculator.h"
#include "OperatorFactory.h"
#include <stdexcept>
using std::stod;
using std::invalid_argument;

double Calculator::readNum(string::const_iterator &it) noexcept
{
    string t;
    while(isNum(it))
        t += *it++;
    if(t == "pi")
        return atan(1.0) * 4;
    return stod(t);
}

double Calculator::readNum_chk(string::const_iterator &it)
{
    string t;
    uint32_t num_dots(0);
    while(isNum(it)) {
        if(*it == '.')
            ++num_dots;
        t += *it++;
    }
    if(num_dots > 1)
        throw invalid_argument(t + ": invalid operand");
    if(t == "pi")
        return atan(1.0) * 4;
    try {
        return stod(t);
    }
    catch (invalid_argument &e) {
        Q_UNUSED(e)
        throw invalid_argument(t + ": invalid operand");
    }
}

string Calculator::readFun(string::const_iterator &it) noexcept
{
    string t;
    while(isLetter(it))
        t += *it++;
    return t;
}

unique_ptr<Operator> Calculator::readOpr(string::const_iterator &it) noexcept
{
    if(isLetter(it))
        return Factory::create(readFun(it));
    else
        return Factory::create(string() + *it++);
}

unique_ptr<Operator> Calculator::readOpr_chk(string::const_iterator &it)
{
    if(isLetter(it)){
        string opr = readFun(it);
        auto oo = Factory::create(opr);
        if(!oo)
            throw invalid_argument(opr + ": undefined operator");
        return oo;
    }
    else{
        auto oo = Factory::create(string() + *it++);
        if(!oo)
            throw invalid_argument(string() + *(it - 1) +
                                   ": undefined operaotr");
        return oo;
    }
}

void Calculator::calculate()
{
    double a[2] = { 0 };
    for (uint32_t i = 0; i < m_opr.top()->numOprand(); ++i) {
        a[i] = m_num.top();
        m_num.pop();
    }
    m_num.push(m_opr.top()->get(a[1], a[0]));
    m_opr.pop();
}

void Calculator::calculate_chk()
{
    for (uint32_t i(0); i < m_opr.top()->numOprand(); ++i) {
        if(m_num.empty())
            throw  invalid_argument("operator \"" + m_opr.top()->symbol()
                                    + "\": no matching operand");
        m_num.pop();
    }
    m_num.push(0);
    m_numOprdNeed -= m_opr.top()->numPushStkOprd();
    m_opr.pop();
}

void Calculator::expr_check(std::string &expr)
{
    uint32_t num_lBracket(0), num_rBracket(0);
    m_numOprdNeed = 0;
    m_num.clear();
    m_opr.clear();
    m_opr.push(make_unique<Hash>());
    remove_space(expr);
    expr += '=';
    for(string::const_iterator it = expr.begin(); it != expr.end();) {
        if (isNum(it))
            m_num.push(readNum_chk(it));
        else{
            auto oo = readOpr_chk(it);
            if (oo->symbol() == "(") ++num_lBracket;
            else if (oo->symbol() == ")") ++num_rBracket;
            while (oo->precedence() <= m_opr.top()->precedence()
                   && (m_opr.top()->symbol() != "(" || oo->symbol() == ")")) {
                if (m_opr.top()->symbol() == "#")
                    break;
                if (m_opr.top()->symbol() == "(" && oo->symbol() == ")") {
                    calculate_chk();
                    break;
                }
                calculate_chk();
            }
            if(oo->symbol() != ")" && oo->symbol() != "="){
                m_numOprdNeed += oo->numPushStkOprd();
                if(m_numOprdNeed != m_num.size())
                    throw invalid_argument("operator \"" + oo->symbol()
                                           + "\": no matching operand");
                m_opr.push(std::move(oo));
            }
        }
    }
    if(num_lBracket != num_rBracket)
        throw invalid_argument("bracket don't match");
    m_num.pop();
    if(!m_num.empty())
        throw invalid_argument("syntax error");
}

void Calculator::remove_space(std::string &expr)
{
    size_t index(0);
    while ((index = expr.find(' ', index)) != string::npos)
        expr.erase(index, 1);
}

double Calculator::doIt(string &expr)
{
    expr_check(expr);
    for (string::const_iterator it = expr.begin(); it != expr.end();) {
        if (isNum(it))
            m_num.push(readNum(it));
        else {
            auto oo = readOpr(it);
            while (oo->precedence() <= m_opr.top()->precedence()
                && (m_opr.top()->symbol() != "(" || oo->symbol() == ")")) {
                if (m_opr.top()->symbol() == "#")
                    break;
                if (m_opr.top()->symbol() == "(" && oo->symbol() == ")") {
                    calculate();
                    break;
                }
                calculate();
            }
            if (oo->symbol() != ")" && oo->symbol() != "=")
                m_opr.push(std::move(oo));
        }
    }
    double result = m_num.top();
    m_num.pop();
    return result;
}
