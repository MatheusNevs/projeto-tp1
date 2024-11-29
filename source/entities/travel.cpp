#include "../../include/entities/travel.hpp"

Travel::Travel(const Code &code, Name &name, Rating &rating) : code(code), name(name), rating(rating) {}

Code Travel::getCode() const
{
    return code;
}

void Travel::setCode(const Code &code)
{
    this->code = code;
}

Name Travel::getName() const
{
    return name;
}

void Travel::setName(const Name &name)
{
    this->name = name;
}

Rating Travel::getRating() const
{
    return rating;
}

void Travel::setRating(const Rating &rating)
{
    this->rating = rating;
}
