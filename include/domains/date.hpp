#include "./domain.hpp"

/** 
 * @class Date
 * @brief Representa uma data validada.
 * 
 * A classe `Date` herda de `Domain` e implementa validação específica para 
 * datas no formato válido, considerando anos bissextos e dias de cada mês.
 */
class Date : public Domain
{
private:
    static const int leapFebruaryDays = 29; 
    static const int notLeapFebruaryDays = 28; 
    static const vector<int> monthDays; 
    static const int monthMax = 12; 
    static const int yearMax = 99; 

    /**
     * @brief Valida a data fornecida.
     * 
     * Verifica se a data segue o formato correto e se os valores são válidos para 
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
     * Inicializa a instância validando e definindo o valor da data.
     * 
     * @param value Data inicial.
     * @throw invalid_argument Se a data for inválida.
     */
    Date(string value);
};


inline Date::Date(string value)
{
  this->setValue(value);
}

const std::vector<int> Date::monthDays = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
