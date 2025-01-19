#ifndef AUTH_VIEW_INTERFACE_H
#define AUTH_VIEW_INTERFACE_H

#include "../interfaces/presentation.hpp"
#include "../domains/password.hpp"
#include "../services/auth.hpp"

class AuthView : public PresentationInterface
{
private:
  AuthModel *authService;

public:
  AuthView(Code &userCode) : PresentationInterface(userCode) {};
  void setAuthService(AuthModel *authService)
  {
    this->authService = authService;
  };
  void autenticate();
  void create();
  void logout();
  void execute(Code &userCode);
  ~AuthView() override
  {
    delete authService;
  };
};

#endif // AUTH_VIEW_INTERFACE_H