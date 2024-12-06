#ifndef ACCOUNT_ENTITY_INTERFACE_H
#define ACCOUNT_ENTITY_INTERFACE_H

#include "../domains/code.hpp"
#include "../domains/password.hpp"
#include "./entity.hpp"

/**
 * @class Account
 * @brief Representa uma entidade `Account` composta por um código e uma senha.
 *
 * A classe `Account` encapsula informações sobre uma conta, como código,
 * e senha. Permite a manipulação e retorno dessas informações através dos
 * métodos `get` e `set`.
 */
class Account : public Entity
{
private:
    Code code;         ///< Código único associado à conta.
    Password password; ///< Senha associada à conta.

public:
    /**
     * @brief Construtor da classe `Account`.
     *
     * Inicializa a conta com um código e uma senha.
     *
     * @param code Referência ao código da conta.
     * @param password Referência à senha da conta.
     */
    Account(const Code &code, const Password &password);

    /**
     * @brief Define um domínio para uma determinada propriedade da Conta.
     *
     * A propriedade pode ser o código ou a senha.
     *
     * @param domain Domínio a ser atribuido a sua respectiva propriedade
     * @param propertyName Nome da propriedade a qual dominínio será associado
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &domain, string propertyName) override;

    /**
     * @brief Retorna o domínio de uma propriedade da conta.
     *
     * A propriedade pode ser o código ou a senha.
     *
     * @param propertyName` Nome da propriedade a ser retornada.
     * @return const Domain& Referência à propriedade retornada.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};

#endif // ACCOUNT_ENTITY_INTERFACE_H
