#ifndef OPERATOR_H
#define OPERATOR_H

#include <string.h>
#include <QtMath>
#include <stdexcept>
using std::string;

class Operator{
protected:
    const string m_symbol;
    const uint32_t m_numOprand;
    const uint32_t m_precedence;
    const uint32_t m_numPushStkOprd;
    enum class angle_unit{
        degree_measure, radian_measure
    };
    static angle_unit angle_mode;

public:
    Operator(const string &symbol, uint32_t numOprd, uint32_t pre, uint32_t numPSOprd):
        m_symbol(symbol), m_numOprand(numOprd), m_precedence(pre)
      , m_numPushStkOprd(numPSOprd) {}
    const string& symbol() const {return m_symbol;}
    uint32_t numOprand() const {return m_numOprand;}
    uint32_t precedence() const { return m_precedence; }
    uint32_t numPushStkOprd() const { return m_numPushStkOprd;}
    virtual double get(double a, double b) const = 0;
    static void setDegMode();
    static void setRadMode();
    virtual ~Operator();
};

class Plus :public Operator {
public:
    Plus() :Operator("+", 2, 3, 1) {}
    double get(double a, double b) const;
};

class Minus :public Operator {
public:
    Minus() :Operator("-", 2, 3, 1) {}
    double get(double a, double b) const;
};

class Multiply :public Operator {
public:
    Multiply() :Operator("*", 2, 4, 1) {}
    double get(double a, double b) const;
};

class Divide :public Operator {
public:
    Divide() :Operator("/", 2, 4, 1) {}
    double get(double a, double b) const;
};

class Mod :public Operator {
public:
    Mod() :Operator("%", 2, 4, 1) {}
    double get(double a, double b) const;
};

class Negative: public Operator{
public:
    Negative() :Operator("~", 1, 5, 0) {}
    double get(double a, double b) const;
};

class Power :public Operator {
public:
    Power() :Operator("^", 2, 6, 1) {}
    double get(double a, double b) const;
};

class Sine :public Operator {
public:
    Sine() :Operator("sin", 1, 7, 0) {}
    double get(double a, double b) const;
};

class ArcSine :public Operator {
public:
    ArcSine() :Operator("asin", 1, 7, 0) {}
    double get(double a, double b) const;
};

class Cosine :public Operator {
public:
    Cosine() :Operator("cos", 1, 7, 0) {}
    double get(double a, double b) const;
};

class ArcCosine :public Operator {
public:
    ArcCosine() :Operator("acos", 1, 7, 0) {}
    double get(double a, double b) const;
};

class Tangent :public Operator {
public:
    Tangent() :Operator("tan", 1, 7, 0) {}
    double get(double a, double b) const;
};

class ArcTangent :public Operator {
public:
    ArcTangent() :Operator("atan", 1, 7, 0) {}
    double get(double a, double b) const;
};

class Square :public Operator {
public:
    Square() :Operator("sqrt", 1, 7, 0) {}
    double get(double a, double b) const;
};

class LN :public Operator {
public:
    LN() :Operator("ln", 1, 7, 0) {}
    double get(double a, double b) const;
};

class LOG :public Operator {
public:
    LOG() :Operator("log", 2, 7, 1) {}
    double get(double a, double b) const;
};

class Exp :public Operator {
public:
    Exp() :Operator("exp", 1, 7, 0) {}
    double get(double a, double b) const;
};

class Factorial :public Operator {
public:
    Factorial() :Operator("!", 1, 7, 1) {}
    double get(double a, double b) const;
};

class Left_Bracket :public Operator {
public:
    Left_Bracket() :Operator("(", 1, 8, 0) {}
    double get(double a, double b) const;
};

class Right_Bracket :public Operator {
public:
    Right_Bracket() :Operator(")", 0, 2, 0) {}
    double get(double a, double b) const;
};

class Hash :public Operator {
public:
    Hash() :Operator("#", 1, 1, 0) {}
    double get(double a, double b) const;
};

class Equal :public Operator { //expr end flag
public:
    Equal() :Operator("=", 2, 0, 0) {}
    double get(double a, double b) const;
};

#endif // OPERATOR_H
