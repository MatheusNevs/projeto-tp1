#include "../../include/domains/rating.hpp"

/**
 * @brief Valida o valor da avaliação fornecido como string.
 *
 * Este método converte o valor de avaliação de string para inteiro
 * e verifica se está dentro do intervalo permitido (0 a 5).
 *
 * @param value O valor da avaliação a ser validado, como uma string.
 * @return True se o valor da avaliação for válido (entre 0 e 5), false caso contrário.
 */
void Rating::validate(string value)
{
    int unsignedNewRating = stoi(value);

    if (unsignedNewRating < 0 || unsignedNewRating > 5)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
