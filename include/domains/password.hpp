#ifndef PASSWORD_DOMAIN_INTERFACE_H
#define PASSWORD_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/** @brief Classe Password
 *
 * Classe responsável pela validação e armazenamento de uma senha. Herda de Domain.
 */
class Password : public Domain
{
protected:
    /** @brief Método de validação
     *
     * Método responsável por validar se a string de senha cumpre os requisitos necessários.
     *
     * @param entrada string que será validada.
     * @throw invalid_argument caso a senha não cumpra os requisitos.
     */
    void validate(string value) override;

public:
    Password(string value);
};

inline Password::Password(string value)
{
    this->setValue(value);
}

#endif // PASSWORD_DOMAIN_INTERFACE_H