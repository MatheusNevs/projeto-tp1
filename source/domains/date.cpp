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

int Date::calculateDateRange(string initialDate, string finalDate)
{
  // Separando os valores DD, MM e YY
  vector<string> splitedInitialDate = split(initialDate, "-");
  vector<string> splitedFinalDate = split(finalDate, "-");

  // Convertemos os componentes da data para inteiros
  int initialDays = stoi(splitedInitialDate[0]);
  int initialMonths = stoi(splitedInitialDate[1]);
  int initialYears = stoi(splitedInitialDate[2]);

  int finalDays = stoi(splitedFinalDate[0]);
  int finalMonths = stoi(splitedFinalDate[1]);
  int finalYears = stoi(splitedFinalDate[2]);

  // Verifica se a data inicial é posterior à data final
  if (initialYears > finalYears ||
      (initialYears == finalYears && initialMonths > finalMonths) ||
      (initialYears == finalYears && initialMonths == finalMonths && initialDays > finalDays))
  {
    throw invalid_argument("Argumento invalido: data inicial posterior à data final.");
  }

  // Calculando a diferença entre as datas
  int days = finalDays - initialDays;
  int months = finalMonths - initialMonths;
  int years = finalYears - initialYears;

  // Verificando se a diferença de dias é negativa
  if (days < 0)
  {
    // Verificando se o mês anterior é fevereiro
    if (initialMonths == 2)
    {
      // Verificando se o ano é bissexto
      if (initialYears % 4 == 0)
      {
        days += leapFebruaryDays;
      }
      else
      {
        days += notLeapFebruaryDays;
      }
    }
    else
    {
      days += monthDays[initialMonths - 1];
    }

    // Decrementando o mês
    months--;
  }

  // Verificando se a diferença de meses é negativa
  if (months < 0)
  {
    months += monthMax;
    years--;
  }

  // Calculando a diferença total em dias
  int totalDays = years * 365 + months * 30 + days;

  // Ajustando para anos bissextos
  totalDays += years / 4;

  return totalDays;
}

bool Date::isWithinRange(string date, string initialDate, string finalDate)
{
  // Separando os valores DD, MM e YY
  vector<string> splitedDate = split(date, "-");
  vector<string> splitedInitialDate = split(initialDate, "-");
  vector<string> splitedFinalDate = split(finalDate, "-");

  // Convertemos os componentes da data para inteiros
  int inputDays = stoi(splitedDate[0]);
  int inputMonths = stoi(splitedDate[1]);
  int inputYears = stoi(splitedDate[2]);

  int initialDays = stoi(splitedInitialDate[0]);
  int initialMonths = stoi(splitedInitialDate[1]);
  int initialYears = stoi(splitedInitialDate[2]);

  int finalDays = stoi(splitedFinalDate[0]);
  int finalMonths = stoi(splitedFinalDate[1]);
  int finalYears = stoi(splitedFinalDate[2]);

  // Verifica se a data está dentro do intervalo
  if (inputYears > initialYears && inputYears < finalYears)
  {
    return true;
  }
  else if (inputYears == initialYears && inputMonths > initialMonths)
  {
    return true;
  }
  else if (inputYears == finalYears && inputMonths < finalMonths)
  {
    return true;
  }
  else if (inputYears == initialYears && inputMonths == initialMonths && inputDays >= initialDays)
  {
    return true;
  }
  else if (inputYears == finalYears && inputMonths == finalMonths && inputDays <= finalDays)
  {
    return true;
  }
  else
  {
    return false;
  }
}
