#ifndef DOMAIN_INTERFACE_H
#define DOMAIN_INTERFACE_H

#include <bits/stdc++.h>
using namespace std;

class Domain
{
private:
    string value;
    virtual bool validate(string value);

public:
    /** @brief Método Set.
     *
     * Método responsável pela atribuição do valor, nele é chamado o método validar que verifica se o valor está
     * no formato correto, se estiver será atribuido, caso contrário será retornado throw.
     *
     * @param value string que será validada para atribuição.
     * @throw invalid_argument caso não esteja no formato desejado.
     *
     * @see validate()
     */
    void setValue(const string &value);

    /** @brief Método Get
     *
     * Método responsável por retornar o valor
     *
     * @return valor
     */
    const string &getValue() const;
};

inline void Domain::setValue(const string &value)
{
    if (!validate(value))
    {
        throw invalid_argument("Argumento Inválido para Domínio");
    }
    this->value = value;
}

inline const string &Domain::getValue() const
{
    return this->value;
}

#endif // DOMAIN_INTERFACE_H
