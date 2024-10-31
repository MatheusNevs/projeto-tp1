#include "domain.hpp"
class Name : public Domain
{
private:
    bool validate(string value) override; // Valida se a string está correta
public:
    Name(string value); // metodo construtor
};

inline Name::Name(string value) : Domain(value) {}; // inline do metodo construtor  