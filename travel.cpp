#include "travel.hpp"

/**
 * @class Travel
 * @brief Representa uma viagem com código, nome e avaliação.
 */
Travel::Travel(const Code &code, const Name &name, const Rating &rating) : code(code), name(name), rating(rating) {}

/**
 * @brief Obtém o código da viagem.
 * @return O código da viagem.
 */
Code Travel::getCode() const
{
    return code;
}

/**
 * @brief Define o código da viagem.
 * @param code O novo código a ser atribuído à viagem.
 */
void Travel::setCode(const Code &code)
{
    this->code = code;
}

/**
 * @brief Obtém o nome.
 * @return O nome.
 */
Name Travel::getName() const
{
    return name;
}

/**
 * @brief Define o nome.
 * @param name O novo nome a ser atribuído.
 */
void Travel::setName(const Name &name)
{
    this->name = name;
}

/**
 * @brief Obtém a avaliação da viagem.
 * @return A avaliação da viagem.
 */
Rating Travel::getRating() const
{
    return rating;
}

/**
 * @brief Define a avaliação da viagem.
 * @param rating A nova avaliação a ser atribuída à viagem.
 */
void Travel::setRating(const Rating &rating)
{
    this->rating = rating;
}
