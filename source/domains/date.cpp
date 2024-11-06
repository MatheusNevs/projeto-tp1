#include "date.hpp"
#include "utils.hpp"
using namespace Utils;

/** @brief Método Validate.
 *
 * Método responsável pela validação dos dados de entrada
 * do domínio Date, que verifica se o valor dado está no
 * formato DD-MM-YY, onde DD é maior do que 0 e menor/igual
 * que 31, MM maior do que 0 e menor/igual do que 12,
 * YY maior/igual a 00 e menor/igual a 99. Atentando-se
 * aos casos de anos bissextos.
 *
 * @param value string que será validada para atribuição.
 * @return `true` or `false`
 *
 * @see validate()
 */
bool Date::validate(string value)
{
  // Separando os valores DD, MM e YY
  vector<string> splitedValue = split(value, "-");

  // Se não houver 3 segmentos, inválido
  if (splitedValue.size() != 3)
  {
    return false;
  };

  int inputYears = stoi(splitedValue[2]);
  int inputMonths = stoi(splitedValue[1]);

  // Verificando limite de intervalos de cada segmento
  if (inputYears < 0 || inputYears > yearMax || inputMonths < 1 || inputMonths > monthMax || inputYears < 1)
    return false;

  int inputDays = stoi(splitedValue[0]);
  int maxDays = monthDays[inputMonths - 1];

  // Verificando limite de intervalos de dias para casos específicos
  if ((inputMonths == 2 &&
       ((inputYears % 4 == 0 && inputDays > leapFebruaryDays) ||
        (!inputYears % 4 == 0 && inputDays > notLeapFebruaryDays))) ||
      (inputMonths != 2 && (inputDays > maxDays)))
  {
    return false;
  }

  return true;
};
