#include "../domains/code.hpp"
#include "../domains/password.hpp"
#include "./entity.hpp"

/**
 * @class Account
 * @brief Representa uma conta composta por código e senha.
 *
 * A classe `Account` gerencia as operações de manipulação de código e senha
 * utilizando os domínios `Code` e `Password`.
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
     * @brief Define um valor para uma propriedade da conta.
     *
     * A propriedade pode ser o código ou a senha.
     *
     * @param propertyName Nome da propriedade a ser modificada.
     * @param value Novo valor a ser atribuído à propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &value) override;

    /**
     * @brief Retorna o valor de uma propriedade da conta.
     *
     * A propriedade pode ser o código ou a senha.
     *
     * @param propertyName Nome da propriedade a ser recuperada.
     * @return const Domain& Valor da propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};
