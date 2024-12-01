#include "../../include/domains/time.hpp"

void Time::validate(string value)
{
  // Posicao do ":" para dividir horas de minutos
  int dividePos = value.find(":");

  // Caso não tenha o ":", inválido
  if (!dividePos)
  {
    throw invalid_argument("Argumento invalido.");
  }

  string hourString = value.substr(0, dividePos);
  string minutesString = value.substr(dividePos + 1, -1);

  // Caso o tamanho da string de hora ou minutos seja diferente de 2, inválido
  if (hourString.length() != 2 || minutesString.length() != 2)
  {
    throw invalid_argument("Argumento invalido.");
  }

  // Caracteres que nao sao numeros na string das horas
  for (char c : hourString)
  {
    if (!isdigit(c))
    {
        throw invalid_argument("Argumento invalido.");
    }
  }

  // Caracteres que nao sao numeros na string dos minutos
  for (char c : minutesString)
  {
    if (!isdigit(c))
    {
        throw invalid_argument("Argumento invalido.");
    }
  }

  int hour = stoi(hourString);
  int minutes = stoi(minutesString);

  // Caso seja negativo ou exceda o máximo dos valores respectivos, inválido
  if (hour < 0 || hour > hourMax || minutes < 0 || minutes > minutesMax)
  {
    throw invalid_argument("Argumento invalido.");
  }
}