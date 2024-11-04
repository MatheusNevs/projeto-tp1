#include "domain.hpp"

class Date : public Domain
{
private:
  const int leapFebruaryDays = 29;
  const int notLeapFebruaryDays = 28;
  const vector<int> monthDays = {
      31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int monthMax = 12;
  const int yearMax = 99;

  // Funcao de validar especifica das datas
  bool validate(string value) override;

public:
  // Método Construtor
  Date(string value);
};

inline Date::Date(string value) : Domain(value) {}