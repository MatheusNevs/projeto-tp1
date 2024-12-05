// Classe implementada pelo aluno com matrícula 231013672

#ifndef DOMAIN_INTERFACE_H
#define DOMAIN_INTERFACE_H

#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

/**
 * @class Domain
 * @brief Representa uma classe domínio abstrata `Domain`, na qual
 * os respectivos domínios irão se construir sobre.
 *
 * A classe `Domain` possui métodos abstratos que irão ser
 * implementados pelos domínios e métodos já implementados que
 * irão ser usados da mesma forma para todos os domínios.
 */
class Domain
{
private:
    string value; ///< Valor do domínio

    /** @brief Método Validate.
     *
     * Método abstrato responsável pela validação dos dados de entrada
     * de determinado domínio, caso o valor recebido seja inválido
     * é levantado o erro `invalid_argument`.
     *
     * @param value string que será validada para atribuição.
     * @throw invalid_argument
     */
    virtual void validate(string value) = 0;

public:
    /** @brief Destrutor virtual
     *
     * Destrutor virtual para garantir que a destruição de objetos derivados
     * seja tratada corretamente.
     */
    virtual ~Domain() = default;

    /** @brief Método Set.
     *
     * Método responsável pela atribuição do valor, nele é chamado o método validar que verifica se o valor está
     * no formato correto, se estiver será atribuido, caso contrário será levantado o erro `invalid_argument`.
     *
     * @param value string que será validada para atribuição.
     * @throw invalid_argument caso não esteja no formato desejado.
     *
     * @see validate()
     */
    void setValue(const string &value);

    /** @brief Método Get.
     *
     * Método responsável por retornar uma referência do `value` do domínio a ser manipulado.
     *
     * @return &`value` referência do valor do domínio.
     */
    const string &getValue() const;
};

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
