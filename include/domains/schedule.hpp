#ifndef SCHEDULE_HPP 
#define SCHEDULE_HPP 

#include "./domain.hpp"

/** 
 * @class Schedule
 * @brief Representa um horário validado.
 * 
 * A classe `Schedule` herda de `Domain` e implementa validação específica para 
 * horários no formato de horas e minutos.
 */
class Schedule : public Domain
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
     * @brief Construtor da classe `Schedule`.
     * 
     * Inicializa a instância validando e definindo o horário.
     * 
     * @param value Horário inicial.
     * @throw invalid_argument Se o horário for inválido.
     */
    Schedule(string value);
};


inline Schedule::Schedule(string value)
{
  this->setValue(value);
}


#endif
