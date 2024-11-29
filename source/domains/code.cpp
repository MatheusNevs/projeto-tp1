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
