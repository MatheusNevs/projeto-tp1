#include "../../include/entities/account.hpp"

Account::Account(const Code &code, const Password &password)
    : code(code), password(password) {}

void Account::set(const Domain &domain, string propertyName)
{
  // Verificação da propriedade para associação do domínio
  if (propertyName == "code")
  {
    this->code = static_cast<const Code &>(domain);
  }
  else if (propertyName == "password")
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
