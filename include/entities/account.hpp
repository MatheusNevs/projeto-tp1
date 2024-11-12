#include "code.hpp"
#include "password.hpp"

class Account
{
private:
  Code code;
  Password password;

public:
  // Método construtor
  Account(Code &, Password &);

  // Atualizar/retornar código
  void setCode(string);
  string getCode();

  // Atualizar/retornar senha
  void setPassword(string);
  string getPassword();
};
