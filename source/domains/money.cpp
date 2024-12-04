// Classe implementada pelo aluno com matrícula 231025181

#include "../../include/domains/money.hpp"

void Money::validate(string value)
{
    // Remover espaços em branco antes de validar
    value.erase(remove(value.begin(), value.end(), ' '), value.end());

    // Se houver ponto E virgula
    if (value.find(".") != string::npos && value.find(",") != string::npos) 
    {
        // Remove ponto e substitui virgula por ponto 
        value.erase(remove(value.begin(), value.end(), '.'), value.end());
        replace(value.begin(), value.end(), ',', '.');
    }

    // Somente números e, opcionalmente, até 2 casas decimais
    if (!regex_match(value, regex(R"(^\d+(\.\d{1,2})?$)")))
    {
        throw invalid_argument("Argumento invalido: formato incorreto.");
    }

    float quantity = stof(value);
    
    if (quantity < moneyMin || quantity > moneyMax)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
