#include "./domain.hpp"

/** 
 * @class Money
 * @brief Representa um valor monetário validado.
 * 
 * A classe `Money` herda de `Domain` e implementa validação específica para valores 
 * monetários dentro de um intervalo definido.
 */
class Money : public Domain
{
private:
    static const float moneyMax = 200000.00; ///< Valor máximo permitido.
    static const float moneyMin = 0.00; ///< Valor mínimo permitido.

    /**
     * @brief Valida o valor monetário fornecido.
     * 
     * Verifica se o valor está dentro do intervalo permitido e no formato correto.
     * 
     * @param value Valor monetário a ser validado.
     * @throw invalid_argument Se o valor for inválido.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Money`.
     * 
     * Inicializa a instância validando e definindo o valor monetário.
     * 
     * @param value Valor inicial.
     * @throw invalid_argument Se o valor for inválido.
     */
    Money(string value);
};


inline Money::Money(string value)
{
    this->setValue(value);
}