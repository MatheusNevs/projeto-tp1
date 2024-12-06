#ifndef LODGING_ENTITY_INTERFACE_H
#define LODGING_ENTITY_INTERFACE_H

#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"

/**
 * @class Lodging
 * @brief Representa uma entidade `Lodging` composta por um código, nome,
 * diária e avaliação.
 *
 * A classe `Lodging` encapsula atributos relacionados a uma hospedagem.
 *  * A classe `Lodging` encapsula informações sobre uma hospedagem, como código,
 * nome, diária e avaliação. Permite a manipulação e retorno dessas informações através
 * dos métodos `get` e `set`.
 */
class Lodging : public Entity
{
private:
    Code code;       ///< Código da hospedagem.
    Name name;       ///< Nome da hospedagem.
    Money dailyRate; ///< Valor da diária da hospedagem.
    Rating rating;   ///< Avaliação da hospedagem.

public:
    /**
     * @brief Construtor da classe `Lodging`.
     *
     * Inicializa a hospedagem com um código, nome, diária e avaliação.
     *
     * @param code Código da hospedagem.
     * @param name Nome da hospedagem.
     * @param dailyRate Valor da diária.
     * @param rating Avaliação da hospedagem.
     */
    Lodging(const Code &code, const Name &name, const Money &dailyRate, const Rating &rating);

    /**
     * @brief Define um domínio para uma determinada propriedade da classe.
     *
     * A propriedade pode ser o código, nome, valor da diária ou avaliação.
     *
     * @param domain Dominio a ser atribuido a sua respectiva propriedade
     * @param propertyName Nome da propriedade a qual dominínio será associado
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &domain, string propertyName) override;

    /**
     * @brief Retorna o domínio de uma propriedade da hospedagem.
     *
     * A propriedade pode ser o código, nome, diária ou avaliação.
     *
     * @param propertyName Nome da propriedade a ser retornada.
     * @return const Domain& Referência à propriedade retornada.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};

#endif // LODGING_ENTITY_INTERFACE_H
