#include "../../include/entities/account.hpp"

Account::Account(Code &code, Password &password) : code(code), password(password) {}

void Account::setCode(Code &code)
{
  this->code = code;
}

Code Account::getCode()
{
  return this->code;
}

void Account::setPassword(Password &password)
{
  this->password = password;
}

Password Account::getPassword()
{
  return this->password;
}