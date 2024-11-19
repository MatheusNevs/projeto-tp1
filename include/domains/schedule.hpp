#include "./domain.hpp"

class Schedule : public Domain
{
private:
  // Numero maximo para digito das horas
  static const int hourMax = 23;

  // Numero maximo para digito dos minutos
  static const int minutesMax = 59;

  // Funcao de validar especifica dos horarios
  void validate(string value) override;

public:
  // Método Construtor
  Schedule(string value);
};

inline Schedule::Schedule(string value)
{
  this->setValue(value);
}