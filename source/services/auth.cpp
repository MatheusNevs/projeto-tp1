#include "../../include/services/auth.hpp"

bool AuthModel::autenticate(Code userCode, Password userPassword)
{
  sqlCommand = "SELECT password FROM account WHERE code = '" + userCode.getValue() + "';";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
    throw invalid_argument("Erro na autenticação");

  if (results[0]["password"] != userPassword.getValue())
    return false;

  return true;
}

void AuthModel::create(Code userCode, Password userPassword)
{
  sqlCommand = "INSERT INTO account (code, password) VALUES ('" + userCode.getValue() + "', '" + userPassword.getValue() + "');";
  results.clear();
  this->execute();

  if (status != SQLITE_OK)
    throw invalid_argument("Erro na criação da conta");
}