#include "lodging.hpp"

// Metodo construtor
Lodging::Lodging(const Code &code, const Name &name, const Money &dailyRate, const Rating &rating) : code(code), name(name), dailyRate(dailyRate), rating(rating) {}

// get e set
Code Lodging::getCode() const
{
    return code;
}

void Lodging::setCode(const Code &code)
{
    this -> code = code;
}

Name Lodging::getName() const
{
    return name;
}

void Lodging::setName(const Name &name)
{
    this -> name = name;
}

Money Lodging::getDailyRate() const
{
    return dailyRate;
}

void Lodging::setDailyRate(const Money &dailyRate)
{
    this -> dailyRate = dailyRate;
}

Rating Lodging::getRating() const
{
    return rating;
}

void Lodging::setRating(const Rating &rating)
{
    this -> rating = rating;
}