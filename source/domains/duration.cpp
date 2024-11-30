#include "../../include/domains/duration.hpp"
#include <stdexcept>

void Duration::validate(string value)
{
    // Verifica se a string contém apenas dígitos
    for (char c : value) {
        if (!isdigit(c)) {
            throw invalid_argument("Valor inválido: Deve ser um número inteiro.");
        }
    }

    // Converte a string para inteiro
    int duration = stoi(value);

    // Verifica se está dentro do intervalo permitido
    if (duration < minDuration || duration > maxDuration) {
        throw invalid_argument("Argumento invalido.");
    }
}
