#include "activity.hpp"

/**
 * @brief Define o código da atividade.
 * @param code Objeto constante do tipo Code que representa o código da atividade.
 */
void Activity::setCode(const Code &code)
{
  this->code = code;
}

/**
 * @brief Retorna o código da atividade.
 * @return Objeto Code que representa o código da atividade.
 */
Code Activity::getCode() const
{
  return code;
}

/**
 * @brief Define o nome da atividade.
 * @param name Objeto constante do tipo Name que representa o nome da atividade.
 */
void Activity::setName(const Name &name)
{
  this->name = name;
}

/**
 * @brief Retorna o nome da atividade.
 * @return Objeto Name que representa o nome da atividade.
 */
Name Activity::getName() const
{
  return name;
}

/**
 * @brief Define a data da atividade.
 * @param date Objeto constante do tipo Date que representa a data da atividade.
 */
void Activity::setDate(const Date &date)
{
  this->date = date;
}

/**
 * @brief Retorna a data da atividade.
 * @return Objeto Date que representa a data da atividade.
 */
Date Activity::getDate() const
{
  return date;
}

/**
 * @brief Define o horário da atividade.
 * @param time Objeto constante do tipo Duration que representa o horário da atividade.
 */
void Activity::setTime(const Duration &time)
{
  this->time = time;
}

/**
 * @brief Retorna o horário da atividade.
 * @return Objeto Duration que representa o horário da atividade.
 */
Duration Activity::getTime() const
{
  return time;
}

/**
 * @brief Define a duração da atividade.
 * @param duration Objeto constante do tipo Duration que representa a duração da atividade.
 */
void Activity::setDuration(const Duration &duration)
{
  this->duration = duration;
}

/**
 * @brief Retorna a duração da atividade.
 * @return Objeto Duration que representa a duração da atividade.
 */
Duration Activity::getDuration() const
{
  return duration;
}

/**
 * @brief Define o preço da atividade.
 * @param price Objeto constante do tipo Money que representa o preço da atividade.
 */
void Activity::setPrice(const Money &price)
{
  this->price = price;
}

/**
 * @brief Retorna o preço da atividade.
 * @return Objeto Money que representa o preço da atividade.
 */
Money Activity::getPrice() const
{
  return price;
}

/**
 * @brief Define a avaliação da atividade.
 * @param rating Objeto constante do tipo Rating que representa a avaliação da atividade.
 */
void Activity::setRating(const Rating &rating)
{
  this->rating = rating;
}

/**
 * @brief Retorna a avaliação da atividade.
 * @return Objeto Rating que representa a avaliação da atividade.
 */
Rating Activity::getRating() const
{
  return rating;
}
