#include "domain.hpp"

class Schedule : public Domain
{
private:
  int hourMax = 23;
  int minutesMax = 59;

  bool validate(string value) override;
};