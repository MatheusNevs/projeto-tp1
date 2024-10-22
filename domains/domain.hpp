#ifndef DOMAIN_INTERFACE_H
#define DOMAIN_INTERFACE_H

#include <bits/stdc++.h>
using namespace std;

class Domain   {
protected:

    string valor;
    virtual void validar(string entrada) = 0;

public:
    /** @brief Método Set.
     *
     * Método responsável pela atribuição do valor, nele é chamado o método validar que verifica se o valor está
     * no formato correto, se estiver será atribuido, caso contrário será retornado throw.
     *
     * @param entrada string que será validada para atribuição.
     * @throw invalid_argument caso não esteja no formato desejado.
     *
     * @see validar()
     */
    void setValor(const string &entrada) {
        validar(entrada);
        this->valor = entrada;
    }

    /** @brief Método Get
     *
     * Método responsável por retornar o valor
     *
     * @return valor
     */
    const string &getValor() const {
        return valor;
    }
};

#endif // DOMAIN_INTERFACE_H