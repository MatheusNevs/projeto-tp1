#ifndef DATE_DOMAIN_INTERFACE_H
#define DATE_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/**
 * @class Date
 * @brief Representa um domínio `Date` de data.
 *
 * A classe `Date` herda de `Domain` e implementa validação específica para
 * datas no formato válido, considerando anos bissextos e dias de cada mês.
 */
class Date : public Domain
{
private:
  static const int leapFebruaryDays = 29;    ///< Dias de fevereiro em anos bissextos.
  static const int notLeapFebruaryDays = 28; ///< Dias de fevereiro em anos normais.
  static const vector<int> monthDays;        ///< Dias por mês (exceto fevereiro variável).
  static const int monthMax = 12;            ///< Número máximo de meses.
  static const int yearMax = 99;             ///< Ano máximo permitido.

  /**
   * @brief Valida a data fornecida.
   *
   * Verifica se a data segue o formato correto (DD-MM-AA) e se os valores são válidos para
   * o calendário.
   *
   * @param value Data a ser validada.
   * @throw invalid_argument Se a data for inválida.
   */
  void validate(string value) override;

public:
  /**
   * @brief Construtor da classe `Date`.
   *
   * Inicializa uma data com o valor fornecido caso válido.
   *
   * @param value Data inicial.
   * @throw invalid_argument Se a data for inválida.
   */
  Date(string value);

  /**
   * @brief Calcula o intervalo de datas.
   *
   * Calcula a diferença entre duas datas fornecidas.
   *
   * @param initialDate Data inicial.
   * @param finalDate Data final.
   * @throw invalid_argument Se a data inicial for posterior à data final.
   */
  static int calculateDateRange(string initialDate, string finalDate);
};

inline Date::Date(string value)
{
  this->setValue(value);
}

#endif // DATE_DOMAIN_INTERFACE_H
