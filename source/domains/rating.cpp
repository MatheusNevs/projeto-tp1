// Classe implementada pelo aluno com matrícula 231025216

#include "../../include/domains/rating.hpp"

void Rating::validate(string value)
{
    int unsignedNewRating = stoi(value);

    if (unsignedNewRating < 0 || unsignedNewRating > 5)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
