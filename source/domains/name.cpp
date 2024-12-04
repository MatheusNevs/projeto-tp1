// Classe implementada pelo aluno com matrícula 231025207

#include "../../include/domains/name.hpp"

void Name::validate(string name)
{
    if (name.length() > 30 || name.empty())
    {
        throw invalid_argument("Argumento invalido.");
    }
}
