#include "password.hpp"
#include <set>
#include <stdexcept> // Para std::invalid_argument

/**
 * @brief Método responsável por validar a senha de acordo com os seguintes requisitos:
 *        - Deve conter exatamente 5 dígitos numéricos (0-9).
 *        - Não pode conter dígitos duplicados.
 *        - Não pode estar em ordem consecutiva crescente (ex: 12345).
 *        - Não pode estar em ordem consecutiva decrescente (ex: 54321).
 *
 * @param entrada A string que representa a senha a ser validada.
 * 
 * @throw invalid_argument Lança uma exceção se a senha não cumprir os requisitos.
 */
void Password::validar(std::string entrada) {
    // Verifica se a senha tem exatamente 5 dígitos
    if (entrada.length() != 5) {
        throw std::invalid_argument("A senha deve ter exatamente 5 dígitos.");
    }

    // Verifica se todos os caracteres são dígitos
    for (char c : entrada) {
        if (!isdigit(c)) {
            throw std::invalid_argument("A senha deve conter apenas dígitos (0-9).");
        }
    }

    // Verifica se há dígitos duplicados
    std::set<char> digitosUnicos(entrada.begin(), entrada.end());
    if (digitosUnicos.size() != 5) {
        throw std::invalid_argument("A senha não pode conter dígitos duplicados.");
    }

    // Verifica se a senha está em ordem consecutiva crescente
    bool isCrescente = true;
    for (size_t i = 1; i < entrada.size(); ++i) {
        if (entrada[i] != entrada[i - 1] + 1) {
            isCrescente = false;
            break;
        }
    }
    if (isCrescente) {
        throw std::invalid_argument("A senha não pode estar em ordem consecutiva crescente.");
    }

    // Verifica se a senha está em ordem consecutiva decrescente
    bool isDecrescente = true;
    for (size_t i = 1; i < entrada.size(); ++i) {
        if (entrada[i] != entrada[i - 1] - 1) {
            isDecrescente = false;
            break;
        }
    }
    if (isDecrescente) {
        throw std::invalid_argument("A senha não pode estar em ordem consecutiva decrescente.");
    }
}
