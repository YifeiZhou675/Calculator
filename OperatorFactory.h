#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include <map>
#include <functional>
#include <memory>
#include "Operator.h"
using std::map;
using std::function;
using std::unique_ptr;
using std::make_unique;

#define REGISTRAR(T, Key)  Factory::RegisterClass<T> reg_##T(Key);

class Factory{
    static map<string, function<unique_ptr<Operator>()>> ms_operator;

public:
    template<typename T>
    struct RegisterClass{
        RegisterClass(const string &opr){
            Factory::ms_operator.emplace(opr, [] {return make_unique<T>(); });
        }
    };

    static unique_ptr<Operator> create(const string &opr){
        auto it = ms_operator.find(opr);
        if(it != ms_operator.end())
            return it->second();
        else
            return nullptr;
    }
};

#endif // OPERATORFACTORY_H
