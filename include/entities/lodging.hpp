#include "../domains/code.hpp"
#include "../domains/name.hpp"
#include "../domains/money.hpp"
#include "../domains/rating.hpp"
#include "./entity.hpp"

/**
 * @class Lodging
 * @brief Representa uma hospedagem com informações de código, nome, diária e avaliação.
 *
 * A classe `Lodging` encapsula atributos relacionados a uma hospedagem.
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
     * Inicializa a hospedagem com os atributos fornecidos.
     *
     * @param code Código da hospedagem.
     * @param name Nome da hospedagem.
     * @param dailyRate Valor da diária.
     * @param rating Avaliação da hospedagem.
     */
    Lodging(const Code &code, const Name &name, const Money &dailyRate, const Rating &rating);

    /**
     * @brief Define um valor para uma propriedade da hospedagem.
     *
     * A propriedade pode ser o código, nome, diária ou avaliação.
     *
     * @param propertyName Nome da propriedade a ser modificada.
     * @param value Novo valor a ser atribuído à propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    void set(const Domain &value) override;

    /**
     * @brief Retorna o valor de uma propriedade da hospedagem.
     *
     * A propriedade pode ser o código, nome, diária ou avaliação.
     *
     * @param propertyName Nome da propriedade a ser recuperada.
     * @return const Domain&
     * @return const Domain& Valor da propriedade.
     * @throw invalid_argument Caso a propriedade não exista.
     */
    const Domain &get(const string propertyName) const override;
};
