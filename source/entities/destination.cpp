#include "../../include/entities/destination.hpp"

void Destination::setCode(const Code &code)
{
    this->code = code;
}

Code Destination::getCode() const
{
    return code;
}

void Destination::setName(const Name &name)
{
    this->name = name;
}

Name Destination::getName() const
{
    return name;
}

void Destination::setArrival(const Date &arrival)
{
    this->arrival = arrival;
}

Date Destination::getArrival() const
{
    return arrival;
}

void Destination::setDeparture(const Date &departure)
{
    this->departure = departure;
}

Date Destination::getDeparture() const
{
    return departure;
}

void Destination::setRating(const Rating &rating)
{
    this->rating = rating;
}

Rating Destination::getRating() const
{
    return rating;
}
