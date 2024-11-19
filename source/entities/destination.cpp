#include "destination.hpp"

/**
 * @brief Define o código do destino.
 * @param code Objeto constante do tipo Code que representa o código do destino.
 */
void Destination::setCode(const Code &code)
{
    this->code = code;
}

/**
 * @brief Retorna o código do destino.
 * @return Objeto Code que representa o código do destino.
 */
Code Destination::getCode() const
{
    return code;
}

/**
 * @brief Define o nome do destino.
 * @param name Objeto constante do tipo Name que representa o nome do destino.
 */
void Destination::setName(const Name &name)
{
    this->name = name;
}

/**
 * @brief Retorna o nome do destino.
 * @return Objeto Name que representa o nome do destino.
 */
Name Destination::getName() const
{
    return name;
}

/**
 * @brief Define a data de chegada ao destino.
 * @param arrival Objeto constante do tipo Date que representa a data de chegada ao destino.
 */
void Destination::setArrival(const Date &arrival)
{
    this->arrival = arrival;
}

/**
 * @brief Retorna a data de chegada ao destino.
 * @return Objeto Date que representa a data de chegada ao destino.
 */
Date Destination::getArrival() const
{
    return arrival;
}

/**
 * @brief Define a data de partida do destino.
 * @param departure Objeto constante do tipo Date que representa a data de partida do destino.
 */
void Destination::setDeparture(const Date &departure)
{
    this->departure = departure;
}

/**
 * @brief Retorna a data de partida do destino.
 * @return Objeto Date que representa a data de partida do destino.
 */
Date Destination::getDeparture() const
{
    return departure;
}

/**
 * @brief Define a avaliação do destino.
 * @param rating Objeto constante do tipo Rating que representa a avaliação do destino.
 */
void Destination::setRating(const Rating &rating)
{
    this->rating = rating;
}

/**
 * @brief Retorna a avaliação do destino.
 * @return Objeto Rating que representa a avaliação do destino.
 */
Rating Destination::getRating() const
{
    return rating;
}
