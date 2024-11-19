#include "account.hpp"

/** @brief Método Construtor.
 *
 * Método responsável pela inicialização do código e da senha
 * membros da classe Account.
 *
 * @param Code, Password
 */
Account::Account(Code &code, Password &password) : code(code), password(password) {}

/** @brief Método setCode.
 *
 * Método responsável pela atualização do valor do código,
 * sujeito a validação do valor de entrada
 *
 * @param value string que será validada e atribuída ao código.
 *
 * @see validate()
 */
void Account::setCode(Code &code)
{
  this->code = code;
}

/** @brief Método getCode.
 *
 * Método responsável pelo retorno do valor do código
 */
Code Account::getCode()
{
  return this->code;
}

/** @brief Método setPassword.
 *
 * Método responsável pela atualização do valor da senha,
 * sujeito a validação do valor de entrada
 *
 * @param value string que será validada e atribuída à senha.
 *
 * @see validate()
 */
void Account::setPassword(Password &password)
{
  this->password = password;
}

/** @brief Método getPassword.
 *
 * Método responsável pelo retorno do valor da senha
 */
Password Account::getPassword()
{
  return this->password;
}