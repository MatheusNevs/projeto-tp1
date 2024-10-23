#include "schedule.hpp"

/** @brief Método Validate.
 *
 * Método responsável pela validação dos dados de entrada
 * do domínio Schedule, verificando o formato "HH:MM",
 * onde HH varia de 00 a 23 e MM de 00 a 59
 *
 * @param value string que será validada para atribuição.
 * @return `true` or `false`
 *
 * @see validate()
 */
bool Schedule::validate(string value)
{
  // Posicao do ":" para dividir horas de minutos
  int dividePos = value.find(":");

  // Caso não tenha o ":", inválido
  if (!dividePos)
    return false;

  string hourString = value.substr(0, dividePos);
  string minutesString = value.substr(dividePos + 1, -1);

  // Caso o tamanho da string de hora ou minutos seja diferente de 2, inválido
  if (hourString.length() != 2 || minutesString.length() != 2)
    return false;

  int hour = stoi(hourString);
  int minutes = stoi(minutesString);

  // Caso seja negativo ou exceda o máximo dos valores respectivos, inválido
  if (hour < 0 || hour > hourMax || minutes < 0 || minutes > minutesMax)
    return false;

  return true;
}