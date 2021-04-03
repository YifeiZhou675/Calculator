#include "Cclt_interface.h"
#include "OperatorFactory.h"

#include <QApplication>

map<string, function<unique_ptr<Operator>()>> Factory::ms_operator;
REGISTRAR(Plus, "+");
REGISTRAR(Minus, "-");
REGISTRAR(Multiply, "*");
REGISTRAR(Divide, "/");
REGISTRAR(Equal, "=");
REGISTRAR(Mod, "%");
REGISTRAR(Power, "^");
REGISTRAR(Sine, "sin");
REGISTRAR(ArcSine, "asin");
REGISTRAR(Cosine, "cos");
REGISTRAR(ArcCosine, "acos");
REGISTRAR(Tangent, "tan");
REGISTRAR(ArcTangent, "atan");
REGISTRAR(Square, "sqrt");
REGISTRAR(LN, "ln");
REGISTRAR(LOG, "log");
REGISTRAR(Exp, "exp");
REGISTRAR(Factorial, "!");
REGISTRAR(Negative, "~");
REGISTRAR(Left_Bracket, "(");
REGISTRAR(Right_Bracket, ")");

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    System w;
    w.show();
    return a.exec();
}
