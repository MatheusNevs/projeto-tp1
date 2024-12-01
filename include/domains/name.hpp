#ifndef NAME_HPP 
#define NAME_HPP 

#include "./domain.hpp"

/** 
 * @class Name
 * @brief Representa um nome validado.
 * 
 * A classe `Name` herda de `Domain` e implementa validação específica para 
 * strings que representam nomes.
 */
class Name : public Domain
{
private:
    /**
     * @brief Valida o nome fornecido.
     * 
     * Verifica se o nome atende aos requisitos de formato e conteúdo.
     * 
     * @param value Nome a ser validado.
     * @throw invalid_argument Se o nome for inválido.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Name`.
     * 
     * Inicializa a instância validando e definindo o nome.
     * 
     * @param value Nome inicial.
     * @throw invalid_argument Se o nome for inválido.
     */
    Name(string value);
};


inline Name::Name(string value)
{
    this->setValue(value);
}


#endif
