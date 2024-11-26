#include "../../include/domains/date.hpp"

#include "utils.hpp"
using namespace Utils;

void Date::validate(string value)
{
  // Separando os valores DD, MM e YY
  vector<string> splitedValue = split(value, "-");

  // Se não houver 3 segmentos, inválido
  if (splitedValue.size() != 3)
  {
    throw invalid_argument("Argumento invalido.");
  };

  int inputYears = stoi(splitedValue[2]);
  int inputMonths = stoi(splitedValue[1]);

  // Verificando limite de intervalos de cada segmento
  if (inputYears < 0 || inputYears > yearMax || inputMonths < 1 || inputMonths > monthMax || inputYears < 1)
  {
    throw invalid_argument("Argumento invalido.");
  }

  int inputDays = stoi(splitedValue[0]);
  int maxDays = monthDays[inputMonths - 1];

  // Verificando limite de intervalos de dias para casos específicos
  if ((inputMonths == 2 &&
       ((inputYears % 4 == 0 && inputDays > leapFebruaryDays) ||
        (!inputYears % 4 == 0 && inputDays > notLeapFebruaryDays))) ||
      (inputMonths != 2 && (inputDays > maxDays)))
  {
    throw invalid_argument("Argumento invalido.");
  }
}
