#ifndef PASSWORD_DOMAIN_INTERFACE_H
#define PASSWORD_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/** @class Password
 * @brief Representa um domínio `Password` de senhas.
 *
 * A classe `Password` herda de `Domain` e implementa validação específica para
 * strings que representam senhas.
 */
class Password : public Domain
{
private:
    /** @brief Método de validação
     *
     * Método responsável por validar se a string de senha cumpre os requisitos necessários:
     * - Cinco dígitos numéricos;
     * - Não pode haver dígito duplicado;
     * - Os dígitos não podem estar em ordem crescente ou decrescente.
     *
     * @param value Senha a ser validada.
     * @throw invalid_argument Caso a senha não cumpra os requisitos.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Password`.
     *
     * Inicializa uma senha com o valor fornecido caso válido.
     *
     * @param value Senha inicial.
     * @throw invalid_argument Se a senha for inválido.
     */
    Password(string value);
};

inline Password::Password(string value)
{
    this->setValue(value);
}

#endif // PASSWORD_DOMAIN_INTERFACE_H
