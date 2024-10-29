#ifndef NAME_HPP_INCLUDED
#define NAME_HPP_INCLUDED

#include "domain.hpp"
#include <string>
using namespace std;

class Name : public Domain {
    private:
        bool validate(const string) override;  // Valida se a string está correta
    public:
        Name(string);
};

inline string Name::Name(string value): Domain(value) {  //inline do metodo construtor
};

#endif 