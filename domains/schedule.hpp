#include "domain.hpp"

class Schedule : public Domain
{
private:
  // Numero maximo para digito das horas
  int hourMax = 23; 
  
  // Numero maximo para digito dos minutos
  int minutesMax = 59; 

  // Funcao de validar especifica dos horarios
  bool validate(string value) override;
};