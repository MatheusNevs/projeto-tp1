#ifndef ACTIVITY_ENTITY_INTERFACE_H
#define ACTIVITY_ENTITY_INTERFACE_H

#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/date.hpp"
#include "../domains/duration.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"

/**
 * @class Activity
 * @brief Representa uma atividade com atributos específicos.
 *
 * A classe `Activity` encapsula informações sobre uma atividade, como código,
 * nome, data, hora de início, duração, preço e avaliação. Permite a manipulação e recuperação
 * dessas informações.
 */
class Activity : public Entity
{
private:
    Code code;         ///< Código da atividade.
    Name name;         ///< Nome da atividade.
    Date date;         ///< Data da atividade.
    Duration time;     ///< Hora de início da atividade.
    Duration duration; ///< Duração da atividade.
    Money price;       ///< Preço da atividade.
    Rating rating;     ///< Avaliação da atividade.

public:
    /**
     * @brief Construtor da classe `Activity`.
     *
     * Inicializa uma atividade com os atributos fornecidos.
     *
     * @param code Código da atividade.
     * @param name Nome da atividade.
     * @param date Data da atividade.
     * @param time Hora de início da atividade.
     * @param duration Duração da atividade.
     * @param price Preço da atividade.
     * @param rating Avaliação da atividade.
     */
    Activity(const Code &code, const Name &name, const Date &date, const Duration &time, const Duration &duration, const Money &price, const Rating &rating);

    /**
     * @brief Define um valor para uma propriedade da atividade.
     *
     * A propriedade pode ser um código, nome, data, horário, duração, preço ou avaliação.
     *
     * @param propertyName Nome da propriedade a qual dominínio será associado
     * @param domain Dominio a ser atribuido a sua respectiva propriedade
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &domain, string propertyName) override;

    /**
     * @brief Retorna o valor de uma propriedade da atividade.
     *
     * A propriedade pode ser qualquer um dos atributos da atividade.
     *
     * @param propertyName Nome da propriedade a ser recuperada.
     * @return const Domain& Valor da propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};

#endif // ACTIVITY_ENTITY_INTERFACE_H
