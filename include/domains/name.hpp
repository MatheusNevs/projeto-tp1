#include "./domain.hpp"

class Name : public Domain
{
private:
    void validate(string value) override; // Valida se a string está correta
public:
    Name(string value); // metodo construtor
};

inline Name::Name(string value)
{
    this->setValue(value);
}