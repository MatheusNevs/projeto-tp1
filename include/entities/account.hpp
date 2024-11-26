#include "../domains/code.hpp"
#include "../domains/password.hpp"

class Account
{
private:
  Code code;
  Password password;

public:
  // Método construtor
  Account(Code &, Password &);

  // Atualizar/retornar código
  void setCode(Code &);
  Code getCode();

  // Atualizar/retornar senha
  void setPassword(Password &);
  Password getPassword();
};
