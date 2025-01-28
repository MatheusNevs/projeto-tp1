#ifndef AUTH_VIEW_INTERFACE_H
#define AUTH_VIEW_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../interfaces/services.hpp"
#include "../domains/password.hpp"

/**
 * @class AuthView
 * @brief Classe responsável pela apresentação da autenticação.
 *
 * A classe AuthView implementa a interface PresentationInterface e gerencia a interação com o serviço de autenticação.
 */
class AuthView : public PresentationInterface
{
private:
  AuthServiceInterface *authService; ///< Serviço de autenticação utilizado pela visualização.

public:
  /**
   * @brief Construtor da classe AuthView.
   *
   * @param userCode Código do usuário.
   */
  AuthView(Code &userCode) : PresentationInterface(userCode) {};

  /**
   * @brief Define o serviço de autenticação a ser utilizado.
   *
   * @param authService Ponteiro para o serviço de autenticação.
   */
  void setAuthService(AuthServiceInterface *authService)
  {
    this->authService = authService;
  };

  /**
   * @brief Autentica um usuário.
   *
   * Interação com usuário para solicitação e autenticação de conta existente no banco de dados.
   */
  void autenticate();

  /**
   * @brief Cria um novo usuário.
   *
   * Interação com usuário para criação de uma nova conta.
   */
  void create();

  /**
   * @brief Realiza o logout do usuário.
   *
   * Interação com usuário para encerramento da sessão de autenticação.
   */
  void logout();

  /**
   * @brief Executa a apresentação de interface visual para autenticação ou criação de conta.
   *
   * @param userCode Código do usuário.
   */
  void execute(Code &userCode);

  /**
   * @brief Destrutor da classe AuthView.
   *
   * Libera os recursos alocados pela classe, incluindo o serviço de autenticação.
   */
  ~AuthView() override
  {
    delete authService;
  };
};

#endif // AUTH_VIEW_INTERFACE_H