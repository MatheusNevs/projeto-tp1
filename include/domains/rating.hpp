#include "./domain.hpp"
/**
 * @class Rating
 * @brief Guarda e valida uma avaliação, garantindo que esteja dentro de um alcance aceitável.
 */
class Rating : public Domain
{
private:
    // Método de validação específico para o domínio Rating
    void validate(string value) override;

public:
    // Método Construtor
    Rating(string value);
};

inline Rating::Rating(string value)
{
    this->setValue(value);
}