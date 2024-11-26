#include "../../include/entities/lodging.hpp"

/**
 * @class Lodging
 * @brief Representa uma acomodação com informações sobre código, nome, tarifa diária e avaliação.
 *
 * A classe `Lodging` é usada para armazenar e manipular as informações de uma acomodação, como o código de identificação,
 * o nome, a tarifa diária e a avaliação. Estes dados são úteis, por exemplo, para gerenciamento de reservas ou exibição
 * em sistemas de hospedagem.
 */
Lodging::Lodging(const Code &code, const Name &name, const Money &dailyRate, const Rating &rating)
    : code(code), name(name), dailyRate(dailyRate), rating(rating) {}

/**
 * @brief Obtém o código da acomodação.
 *
 * Este método retorna o código de identificação único da acomodação.
 *
 * @return O código da acomodação.
 */
Code Lodging::getCode() const
{
    return code;
}

/**
 * @brief Define o código da acomodação.
 *
 * Este método define o código de identificação único da acomodação.
 *
 * @param code O novo código da acomodação.
 */
void Lodging::setCode(const Code &code)
{
    this->code = code;
}

/**
 * @brief Obtém o nome da acomodação.
 *
 * Este método retorna o nome da acomodação.
 *
 * @return O nome da acomodação.
 */
Name Lodging::getName() const
{
    return name;
}

/**
 * @brief Define o nome da acomodação.
 *
 * Este método define o nome da acomodação.
 *
 * @param name O novo nome da acomodação.
 */
void Lodging::setName(const Name &name)
{
    this->name = name;
}

/**
 * @brief Obtém a tarifa diária da acomodação.
 *
 * Este método retorna a tarifa diária que é cobrada para a estadia na acomodação.
 *
 * @return A tarifa diária.
 */
Money Lodging::getDailyRate() const
{
    return dailyRate;
}

/**
 * @brief Define a tarifa diária da acomodação.
 *
 * Este método define a tarifa diária que será cobrada para a estadia na acomodação.
 *
 * @param dailyRate A nova tarifa diária.
 */
void Lodging::setDailyRate(const Money &dailyRate)
{
    this->dailyRate = dailyRate;
}

/**
 * @brief Obtém a avaliação da acomodação.
 *
 * Este método retorna a avaliação atribuída à acomodação, geralmente representada como uma nota de 1 a 5.
 *
 * @return A avaliação da acomodação.
 */
Rating Lodging::getRating() const
{
    return rating;
}

/**
 * @brief Define a avaliação da acomodação.
 *
 * Este método define a avaliação atribuída à acomodação.
 *
 * @param rating A nova avaliação da acomodação.
 */
void Lodging::setRating(const Rating &rating)
{
    this->rating = rating;
}
