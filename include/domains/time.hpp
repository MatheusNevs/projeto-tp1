#ifndef TIME_DOMAIN_INTERFACE_H
#define TIME_DOMAIN_INTERFACE_H

#include "./domain.hpp"

/**
 * @class Time
 * @brief Representa um domínio `Time` de horários.
 *
 * A classe `Time` herda de `Domain` e implementa validação específica para
 * horários no formato de horas e minutos.
 */
class Time : public Domain
{
private:
  static const int hourMax = 23;    ///< Valor máximo para horas.
  static const int minutesMax = 59; ///< Valor máximo para minutos.

  /**
   * @brief Valida o horário fornecido.
   *
   * Verifica se o horário está no formato correto (HH:MM) e dentro dos valores permitidos
   * (00 a 23 para horas, 00 a 59 para minutos).
   *
   * @param value Horário a ser validado.
   * @throw invalid_argument Se o horário for inválido.
   */
  void validate(string value) override;

public:
  /**
   * @brief Construtor da classe `Time`.
   *
   * Inicializa o horário com o valor fornecido caso válido.
   *
   * @param value Horário inicial.
   * @throw invalid_argument Se o horário for inválido.
   */
  Time(string value);
};

inline Time::Time(string value)
{
  this->setValue(value);
}

#endif // TIME_DOMAIN_INTERFACE_H
