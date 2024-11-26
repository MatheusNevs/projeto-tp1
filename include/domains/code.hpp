#include "./domain.hpp"

class Code : public Domain
{
private:
  // Numero maximo para digito das horas
  static const int codeLength = 6;

  // Funcao de validar especifica dos horarios
  void validate(string value) override;

public:
  // Método Construtor
  Code(string value);
};

inline Code::Code(string value)
{
  this->setValue(value);
}