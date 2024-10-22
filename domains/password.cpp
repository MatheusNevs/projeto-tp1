#include "password.hpp"
#include <set>
#include <algorithm> // Para std::is_sorted

/**
 * @brief Método responsável por validar a senha de acordo com os seguintes requisitos:
 *        - Deve conter exatamente 5 dígitos numéricos (0-9).
 *        - Não pode conter dígitos duplicados.
 *        - Não pode estar em ordem crescente (ex: 12345).
 *        - Não pode estar em ordem decrescente (ex: 54321).
 *
 * @param entrada A string que representa a senha a ser validada.
 * 
 * @throw invalid_argument Lança uma exceção se a senha não cumprir os requisitos.
 */
void Password::validar(string entrada) {
    // Verifica se a senha tem exatamente 5 dígitos
    if (entrada.length() != 5) {
        throw invalid_argument("A senha deve ter exatamente 5 dígitos.");
    }

    // Verifica se todos os caracteres são dígitos
    for (char c : entrada) {
        if (!isdigit(c)) {
            throw invalid_argument("A senha deve conter apenas dígitos (0-9).");
        }
    }

    // Verifica se há dígitos duplicados
    set<char> digitosUnicos(entrada.begin(), entrada.end());
    if (digitosUnicos.size() != 5) {
        throw invalid_argument("A senha não pode conter dígitos duplicados.");
    }

    // Verifica se a senha está em ordem crescente
    if (is_sorted(entrada.begin(), entrada.end())) {
        throw invalid_argument("A senha não pode estar em ordem crescente.");
    }

    // Verifica se a senha está em ordem decrescente
    if (is_sorted(entrada.rbegin(), entrada.rend())) {
        throw invalid_argument("A senha não pode estar em ordem decrescente.");
    }
}
