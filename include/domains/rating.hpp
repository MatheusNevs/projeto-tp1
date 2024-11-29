#ifndef RATING_DOMAIN_INTERFACE_H
#define RATING_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/**
 * @class Rating
 * @brief Representa uma avaliação validada.
 *
 * A classe `Rating` herda de `Domain` e implementa validação específica para
 * valores de avaliação, como notas ou classificações.
 */
class Rating : public Domain
{
private:
    /**
     * @brief Valida a avaliação fornecida.
     *
     * Verifica se o valor da avaliação atende aos requisitos do domínio.
     *
     * @param value Avaliação a ser validada.
     * @throw invalid_argument Se a avaliação for inválida.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Rating`.
     *
     * Inicializa a instância validando e definindo o valor da avaliação.
     *
     * @param value Avaliação inicial.
     * @throw invalid_argument Se a avaliação for inválida.
     */
    Rating(string value);
};

inline Rating::Rating(string value)
{
    this->setValue(value);
}

#endif // RATING_DOMAIN_INTERFACE_H