#ifndef ACCOUNT_HPP 
#define ACCOUNT_HPP 

#include "../domains/code.hpp"
#include "../domains/password.hpp"

/**
 * @class Account
 * @brief Representa uma conta composta por código e senha.
 * 
 * A classe `Account` gerencia as operações de manipulação de código e senha
 * utilizando os domínios `Code` e `Password`.
 */
class Account
{
private:
    Code code; ///< Código único associado à conta.
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
     * @brief Define um novo código para a conta.
     * 
     * @param code Novo código a ser associado à conta.
     */
    void setCode(Code &code);

    /**
     * @brief Retorna o código associado à conta.
     * 
     * @return Código da conta.
     */
    Code getCode();

    /**
     * @brief Define uma nova senha para a conta.
     * 
     * @param password Nova senha a ser associada à conta.
     */
    void setPassword(Password &password);

    /**
     * @brief Retorna a senha associada à conta.
     * 
     * @return Senha da conta.
     */
    Password getPassword();
};


#endif
