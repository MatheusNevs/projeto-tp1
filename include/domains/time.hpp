#ifndef TIME_HPP 
#define TIME_HPP 

#include "./domain.hpp"

/** 
 * @class Time
 * @brief Representa um horário validado.
 * 
 * A classe `Time` herda de `Domain` e implementa validação específica para 
 * horários no formato de horas e minutos.
 */
class Time : public Domain
{
private:
    static const int hourMax = 23; ///< Valor máximo para horas.
    static const int minutesMax = 59; ///< Valor máximo para minutos.

    /**
     * @brief Valida o horário fornecido.
     * 
     * Verifica se o horário está no formato correto e dentro dos valores permitidos.
     * 
     * @param value Horário a ser validado.
     * @throw invalid_argument Se o horário for inválido.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Time`.
     * 
     * Inicializa a instância validando e definindo o horário.
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


#endif
