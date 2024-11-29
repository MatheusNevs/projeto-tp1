#include "../../include/entities/account.hpp"
#include <typeinfo> // Necessário para typeid()

Account::Account(const Code &code, const Password &password)
    : code(code), password(password) {}

void Account::set(const Domain &domain)
{
  if (typeid(domain) == typeid(Code))
  {
    this->code = static_cast<const Code &>(domain);
  }
  else if (typeid(domain) == typeid(Password))
  {
    this->password = static_cast<const Password &>(domain);
  }
  else
  {
    throw invalid_argument("Tipo desconhecido para o domínio fornecido");
  }
}

const Domain &Account::get(const string propertyName) const
{
  if (propertyName == "code")
  {
    return this->code;
  }
  else if (propertyName == "password")
  {
    return this->password;
  }
  else
  {
    throw invalid_argument("Propriedade desconhecida");
  }
}
