#ifndef NAME_HPP_INCLUDED
#define NAME_HPP_INCLUDED

#include <string>
using namespace std;

class Name {
    private:
        string value;  // Armazena o nome
        bool validate(const string&);  // Valida se a string está correta
    public:
        bool setName(const string&);   // Define o valor do nome, se for válido
        string getName() const;        // Retorna o valor armazenado
};

inline string Name::getName() const { 
    return value;
};

#endif 