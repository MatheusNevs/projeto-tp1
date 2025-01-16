#include "../interfaces/presentation.hpp"
#include "../domains/password.hpp"
#include "../services/auth.hpp"

class AuthView : public PresentationInterface
{
private:
  AuthModel *authService;
  Code *userCode = nullptr;

public:
  void setAuthService(AuthModel *authService)
  {
    this->authService = authService;
  }
  void autenticate(Code *userCode);
  void create(Code *userCode);
  void logout(Code *userCode);
  void execute(Code &userCode);
};