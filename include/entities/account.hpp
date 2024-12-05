#ifndef ACCOUNT_ENTITY_INTERFACE_H
#define ACCOUNT_ENTITY_INTERFACE_H

#include "../domains/code.hpp"
#include "../domains/password.hpp"
#include "./entity.hpp"

/**
 * @class Account
 * @brief Representa uma entidade `Account` composta por um código e uma senha.
 *
 * A classe `Account` gerencia as operações de manipulação de código e senha
 * utilizando os domínios `Code` e `Password` através de um método `get` e um
 * método `set`.
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
     * @brief Define um domínio para uma determinada propriedade da classe.
     *
     * A propriedade pode ser o código ou a senha.
     *
     * @param domain Domínio a ser atribuido a sua respectiva propriedade
     * @param propertyName Nome da propriedade a qual dominínio será associado
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &domain, string propertyName) override;

    /**
     * @brief Retorna o valor de uma propriedade da conta.
     *
     * A propriedade pode ser o código ou a senha.
     *
     * @param propertyName` Nome da propriedade a ser retornada.
     * @return const Domain& referência à propriedade retornada.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};

#endif // ACCOUNT_ENTITY_INTERFACE_H
