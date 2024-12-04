// Classe implementada pelo aluno com matrícula 231025216

#include "../../include/domains/date.hpp"
#include "../../lib/utils/utils.hpp"
using namespace Utils;

const std::vector<int> Date::monthDays = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::validate(string value)
{
  // Verificar se a data contém "/" e lançar erro caso contenha
  if (value.find("/") != string::npos) 
  {
    throw invalid_argument("Argumento invalido: formato inválido.");
  }

  // Verificar se existe espaço em branco em qualquer parte da string
  if (value.find(" ") != string::npos)
  {
    throw invalid_argument("Argumento invalido: espaços em branco não são permitidos.");
  }

  // Separando os valores DD, MM e YY
  vector<string> splitedValue = split(value, "-");

  // Se não houver exatamente 3 segmentos, inválido
  if (splitedValue.size() != 3)
  {
    throw invalid_argument("Argumento invalidoooo: formato incorreto.");
  };

  // Convertemos os componentes da data para inteiros
  int inputDays = stoi(splitedValue[0]);
  int inputMonths = stoi(splitedValue[1]);
  int inputYears = stoi(splitedValue[2]);

  // Verificando limites de valores para dia, mês e ano
  if (inputYears < 0 || inputYears > yearMax || inputMonths < 1 || inputMonths > monthMax || inputDays < 1)
  {
    throw invalid_argument("Argumento invalido.");
  }

  int maxDays = monthDays[inputMonths - 1];

  // Verificando a quantidade de dias nos meses
  if ((inputMonths == 2 &&
       ((inputYears % 4 == 0 && inputDays > leapFebruaryDays) ||
        (inputYears % 4 != 0 && inputDays > notLeapFebruaryDays))) ||
      (inputMonths != 2 && (inputDays > maxDays)))
  {
    throw invalid_argument("Argumento invalido.");
  }
}
