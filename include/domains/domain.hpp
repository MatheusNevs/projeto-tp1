#ifndef DOMAIN_INTERFACE_H
#define DOMAIN_INTERFACE_H

#include <bits/stdc++.h>
using namespace std;

class Domain
{
private:
    string value;

    /** @brief Método Validate.
     *
     * Método responsável pela validação dos dados de entrada
     * de determinado domínio, retornando true para dados válidos
     * e false para dados inválidos
     *
     * @param value string que será validada para atribuição.
     * @return `true` or `false`
     *
     * @see validate()
     */
    virtual void validate(string value) = 0;

public:
    /** @brief Método Construtor.
     *
     * Método responsável pela inicialização dos valores
     * do domínio, ocorrendo a validação dos dados
     *
     * @param value string que será inicializada na instância
     * @throw invalid_argument caso não esteja no formato desejado.
     *
     * @see validate()
     */

    Domain(string value);

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
     * @return value
     */
    const string &getValue() const;
};

inline Domain::Domain(string value)
{
    setValue(value);
}

inline void Domain::setValue(const string &value)
{
    validate(value);
    this->value = value;
}

inline const string &Domain::getValue() const
{
    return this->value;
}

#endif // DOMAIN_INTERFACE_H
