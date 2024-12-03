#ifndef DURATION_DOMAIN_INTERFACE_H
#define DURATION_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/**
 * @class Duration
 * @brief Representa uma duração de tempo validada.
 *
 * A classe `Duration` herda de `Domain` e implementa validação específica para
 * durações no intervalo permitido.
 */
class Duration : public Domain
{
private:
    static const int minDuration = 0;   ///< Duração mínima permitida.
    static const int maxDuration = 360; ///< Duração máxima permitida.

    /**
     * @brief Valida a duração fornecida.
     *
     * Verifica se a duração está dentro do intervalo permitido.
     *
     * @param value Duração a ser validada.
     * @throw invalid_argument Se a duração for inválida.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Duration`.
     *
     * Inicializa a instância validando e definindo o valor da duração.
     *
     * @param value Duração inicial.
     * @throw invalid_argument Se a duração for inválida.
     */
    Duration(string value);
};

inline Duration::Duration(string value)
{
    this->setValue(value);
}

#endif // DURATION_DOMAIN_INTERFACE_H
