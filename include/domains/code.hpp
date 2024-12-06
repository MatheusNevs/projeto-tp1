#ifndef CODE_DOMAIN_INTERFACE_H
#define CODE_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/**
 * @class Code
 * @brief Representa um domínio `Code` de código alfanumérico.
 *
 * A classe `Code` herda de `Domain` e implementa validação específica para
 * códigos alfanuméricos de tamanho fixo.
 */
class Code : public Domain
{
private:
  static const int codeLength = 6; ///< Comprimento fixo do código.

  /**
   * @brief Valida o código fornecido.
   *
   * Verifica se o código possui o tamanho especificado e atende aos requisitos
   * de formato. Tendo o formato de 6 caracteres alfanuméricos.
   *
   * @param value Código a ser validado.
   * @throw invalid_argument Se o código for inválido.
   */
  void validate(string value) override;

public:
  /**
   * @brief Construtor da classe `Code`.
   *
   * Inicializa um código com o valor fornecido caso válido.
   *
   * @param value Código inicial.
   * @throw invalid_argument Se o código for inválido.
   */
  Code(string value);
};

inline Code::Code(string value)
{
  this->setValue(value);
}

#endif // CODE_DOMAIN_INTERFACE_H
