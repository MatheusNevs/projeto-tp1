#include "code.hpp"

/** @brief Método Validate.
 *
 * Método responsável pela validação dos dados de entrada
 * do domínio Code, que deve estar no formato de seis
 * dígitos alfanuméricos
 *
 * @param value string que será validada para atribuição.
 * @return `true` or `false`
 *
 * @see validate()
 */
void Code::validate(string value)
{
  // Caso tamanho diferente de 6, inválido
  if (value.length() != codeLength)
    throw invalid_argument("Argumento invalido.");

  for (int i = 0; i < 6; i++)
  {
    // Caso caracter não for alfanumérico, inválido
    if (!isalnum(value[i]))
    {
      throw invalid_argument("Argumento invalido.");
    }
  }
};
