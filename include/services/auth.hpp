#ifndef AUTH_MODEL_INTERFACE_H
#define AUTH_MODEL_INTERFACE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

/**
 * @class AuthModel
 * @brief Classe responsável pela autenticação e criação de usuários.
 *
 * A classe AuthModel implementa a interface AuthServiceInterface e herda da classe Model.
 */
class AuthModel : public AuthServiceInterface, public Model
{
public:
  /**
   * @brief Autentica um usuário com base no código e senha fornecidos.
   *
   * @param userCode Código do usuário.
   * @param userPassword Senha do usuário.
   * @return true se a autenticação for bem-sucedida, false caso contrário.
   */
  bool autenticate(Code &userCode, Password &userPassword);

  /**
   * @brief Cria um novo usuário com o código e senha fornecidos.
   *
   * @param userCode Código do usuário.
   * @param userPassword Senha do usuário.
   */
  void create(Code &userCode, Password &userPassword);

  /**
   * @brief Destrutor da classe AuthModel.
   */
  ~AuthModel() override {};
};

#endif // AUTH_MODEL_INTERFACE_H