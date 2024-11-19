#include "./domain.hpp"

class Date : public Domain
{
private:
  static const int leapFebruaryDays = 29;
  static const int notLeapFebruaryDays = 28;
  static const vector<int> monthDays;
  static const int monthMax = 12;
  static const int yearMax = 99;

  // Funcao de validar especifica das datas
  void validate(string value) override;

public:
  // Método Construtor
  Date(string value);
};

inline Date::Date(string value)
{
  this->setValue(value);
}

const std::vector<int> Date::monthDays = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
