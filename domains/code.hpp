#include "domain.hpp"

class Code : public Domain
{
private:
  // Numero maximo para digito das horas
  int codeLenght = 6;

  // Funcao de validar especifica dos horarios
  bool validate(string value) override;
};