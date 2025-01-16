// Classe implementada pelo aluno com matrícula 231013672
#include <cstdlib>
#include <ctime>

#include "../../include/domains/code.hpp"

void Code::validate(string value)
{
  // Caso tamanho diferente de 6, inválido
  if (value.length() != codeLength)
  {
    throw invalid_argument("Argumento invalido.");
  }

  for (int i = 0; i < 6; i++)
  {
    // Caso caracter não for alfanumérico, inválido
    if (!isalnum(value[i]))
    {
      throw invalid_argument("Argumento invalido.");
    }
  }
};

Code::Code()
{
  string randomCode = generateRandomCode();
  setValue(randomCode);
}

string Code::generateRandomCode()
{
  const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const int alphanumLength = sizeof(alphanum) - 1;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, alphanumLength - 1);

  string randomCode;
  for (int i = 0; i < codeLength; i++)
  {
    randomCode += alphanum[dis(gen)];
  }
  return randomCode;
}
