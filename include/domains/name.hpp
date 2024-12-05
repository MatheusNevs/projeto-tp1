#ifndef NAME_DOMAIN_INTERFACE_H
#define NAME_DOMAIN_INTERFACE_H
#include "./domain.hpp"

/**
 * @class Name
 * @brief Representa um domínio `Name` de nomes.
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
     * Verifica se o nome atende aos requisitos (string com até 30 caracteres).
     *
     * @param value Nome a ser validado.
     * @throw invalid_argument Se o nome for inválido.
     */
    void validate(string value) override;

public:
    /**
     * @brief Construtor da classe `Name`.
     *
     * Inicializa um nome com o valor forencido caso válido.
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

#endif // NAME_DOMAIN_INTERFACE_H
