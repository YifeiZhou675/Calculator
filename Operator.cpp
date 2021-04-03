#include "Operator.h"
using std::invalid_argument;
using std::overflow_error;
using std::to_string;

Operator::angle_unit Operator::angle_mode = angle_unit::radian_measure;

void Operator::setDegMode()
{
    angle_mode = angle_unit::degree_measure;
}

void Operator::setRadMode()
{
    angle_mode = angle_unit::radian_measure;
}

Operator::~Operator()
{

}

double Plus::get(double a, double b) const
{
    return a + b;
}

double Minus::get(double a, double b) const
{
    return a - b;
}

double Multiply::get(double a, double b) const
{
    return a * b;
}

double Divide::get(double a, double b) const
{
    if(b == .0)
        throw invalid_argument("'" + to_string(a) + "/0': divisor must be nonzero");
    return a / b;
}

double Mod::get(double a, double b) const
{
    return a - b * static_cast<int>(a / b);
}

double Power::get(double a, double b) const
{
    return qPow(a, b);
}

double Sine::get(double, double b) const
{
    switch (angle_mode) {
    case angle_unit::degree_measure:{
        return qSin(qDegreesToRadians(b));
    }
    case angle_unit::radian_measure:{
        return qSin(b);
    }
    }
}

double Cosine::get(double, double b) const
{
    switch (angle_mode) {
    case angle_unit::degree_measure:{
        return qCos(qDegreesToRadians(b));
    }
    case angle_unit::radian_measure:{
        return qCos(b);
    }
    }
}

double Tangent::get(double, double b) const
{
    switch (angle_mode) {
    case angle_unit::degree_measure:{
        return qTan(qDegreesToRadians(b));
    }
    case angle_unit::radian_measure:{
        return qTan(b);
    }
    }
}

double Square::get(double, double b) const
{
    return qSqrt(b);
}

double LN::get(double, double b) const
{
    if(b <= .0)
        throw  invalid_argument("'ln(" + to_string(b) + ")': antilogarithm must be positive");
    return qLn(b);
}

double LOG::get(double a, double b) const
{
    if(a <= .0)
        throw invalid_argument("log" + to_string(a) + "(" + to_string(b) +
                        "): base must be positive");
    else if(b <= .0)
        throw invalid_argument("log" + to_string(a) + "(" + to_string(b) +
                        "): antilogarithm must be positive");
    return qLn(b) / qLn(a);
}

double Factorial::get(double, double b) const
{
    if(static_cast<int>(b) != b || b < .0)
        throw invalid_argument("'" + to_string(b) + "!': operand must be natural number");
    if(b == .0)
        return 1;
    else{
        double result(1);
        for(int i(1); i <= b; ++i)
            result *= i;
        return result;
    }
}

double Left_Bracket::get(double, double b) const
{
    return b;
}

double Right_Bracket::get(double, double) const
{
    return 0;
}

double Hash::get(double a, double) const
{
    return a;
}

double Equal::get(double a, double) const
{
    return a;
}

double ArcSine::get(double, double b) const
{
    switch (angle_mode) {
    case angle_unit::degree_measure:{
        return qRadiansToDegrees(qAsin(b));
    }
    case angle_unit::radian_measure:{
        return qAsin(b);
    }
    }
}

double Negative::get(double, double b) const
{
    return -b;
}

double ArcCosine::get(double, double b) const
{
    switch (angle_mode) {
    case angle_unit::degree_measure:{
        return qRadiansToDegrees(qAcos(b));
    }
    case angle_unit::radian_measure:{
        return qAcos(b);
    }
    }
}

double ArcTangent::get(double, double b) const
{
    switch (angle_mode) {
    case angle_unit::degree_measure:{
        return qRadiansToDegrees(qAtan(b));
    }
    case angle_unit::radian_measure:{
        return qAtan(b);
    }
    }
}

double Exp::get(double, double b) const
{
    return qExp(b);
}
