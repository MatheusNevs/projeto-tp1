#include "domain.hpp"

/**
 * @class Evaluation
 * @brief Guarda e valida uma avaliação, garantindo que esteja dentro de um alcance aceitável.
 */
class Evaluation : public Domain
{
private:
    // Método de validação específico para o domínio Evaluation
    bool validate(string value) override;

public:
    // Método Construtor
    Evaluation(string value);
};

inline Evaluation::Evaluation(string value) : Domain(value) {}