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
bool Code::validate(string value)
{
  // Caso tamanho diferente de 6, inválido
  if (value.length() != codeLenght)
    return false;

  for (int i = 0; i < 6; i++)
  {
    // Caso caracter não for alfanumérico, inválido
    if (!isalnum(value[i]))
      return false;
  }

  return true;
}
