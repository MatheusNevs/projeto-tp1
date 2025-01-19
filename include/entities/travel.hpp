#ifndef TRAVEL_ENTITY_INTERFACE_H
#define TRAVEL_ENTITY_INTERFACE_H

#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"

/**
 * @class Travel
 * @brief Representa uma entidade `Travel` composta por código,
 * nome e avaliação.
 *
 * A classe `Travel` encapsula atributos relacionados a uma viagem, incluindo código,
 * nome, data de início, data de término e custo total da viagem. Permite a manipulação
 * e retorno dessas informações através dos métodos `get` e `set`.
 */
class Travel : public Entity
{
private:
    Code code;     ///< Código da viagem.
    Name name;     ///< Nome da viagem.
    Rating rating; ///< Avaliação da viagem.

public:
    /**
     * @brief Construtor da classe `Travel`.
     *
     * Inicializa a viagem com um código, nome, data de início,
     * data de fim, custo total e avaliação.
     *
     * @param code Código da viagem.
     * @param name Nome da viagem.
     * @param rating Avaliação da viagem.
     */
    Travel(const Code &code, const Name &name, const Rating &rating);

    /**
     * @brief Define um domínio para uma determinada propriedade da viagem  .
     *
     * A propriedade pode ser o código, nome, data de início, data de término, custo total ou avaliação.
     *
     * @param propertyName Nome da propriedade a qual dominínio será associado
     * @param domain Dominio a ser atribuido a sua respectiva propriedade
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &domain, string propertyName) override;

    /**
     * @brief Retorna o domínio de uma propriedade da viagem.
     *
     * A propriedade pode ser o código, nome, data de início, data de término, custo total ou avaliação.
     *
     * @param propertyName Nome da propriedade a ser retornada.
     * @return const Domain& Referência à propriedade retornada.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};

#endif // TRAVEL_ENTITY_INTERFACE_H
