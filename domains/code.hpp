#include "domain.hpp"

class Code : public Domain
{
private:
  // Numero maximo para digito das horas
  const int codeLenght = 6;

  // Funcao de validar especifica dos horarios
  bool validate(string value) override;

public:
  // Método Construtor
  Code(string value);
};

inline Code::Code(string value) : Domain(value) {}