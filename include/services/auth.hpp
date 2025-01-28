#ifndef AUTH_MODEL_INTERFACE_H
#define AUTH_MODEL_INTERFACE_H

#include "./model.hpp"
#include "../interfaces/services.hpp"

/**
 * @class AuthModel
 * @brief Implementação do serviço relacionado a autenticação.
 *
 * Esta classe herda da classe Model para se comunicar com o banco de dados e
 * implementa a interface de serviço de autenticação, AuthServiceInterface,
 * disponibilizando métodos para manipulação de informações de contas/autenticação
 * em um banco de dados persistente.
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