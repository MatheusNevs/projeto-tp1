#ifndef MONEY_DOMAIN_INTERFACE_H
#define MONEY_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/**
 * @class Money
 * @brief Representa um domínio `Money` de unidade de dinheiro.
 *
 * A classe `Money` herda de `Domain` e implementa validação específica para valores
 * monetários dentro de um intervalo definido.
 */
class Money : public Domain
{
private:
    static constexpr float moneyMax = 200000.00; ///< Valor máximo permitido.
    static constexpr float moneyMin = 0.00;      ///< Valor mínimo permitido.

    /**
     * @brief Valida o valor monetário fornecido.
     *
     * Verifica se o valor está dentro do intervalo permitido de 0 a 200.000 (DUZENTOS MIL).
     *
     * @param value Valor monetário a ser validado.
     * @throw invalid_argument Se o valor for inválido.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Money`.
     *
     * Inicializa um dinheiro com o valor fornecido caso válido.
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

#endif // MONEY_DOMAIN_INTERFACE_H
