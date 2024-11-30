#include "../../include/entities/destination.hpp"

Destination::Destination(const Code &code, const Name &name, const Date &arrival, const Date &departure, const Rating &rating)
    : code(code), name(name), arrival(arrival), departure(departure), rating(rating) {}

void Destination::set(const Domain &domain, string propertyName)
{
    if (propertyName == "code")
    {
        this->code = static_cast<const Code &>(domain);
    }
    else if (propertyName == "name")
    {
        this->name = static_cast<const Name &>(domain);
    }
    else if (propertyName == "arrival")
    {
        this->arrival = static_cast<const Date &>(domain);
    }
    else if (propertyName == "departure")
    {
        this->departure = static_cast<const Date &>(domain);
    }
    else if (propertyName == "rating")
    {
        this->rating = static_cast<const Rating &>(domain);
    }
    else
    {
        throw invalid_argument("Tipo desconhecido para o domínio fornecido");
    }
}

const Domain &Destination::get(const string propertyName)
{
    if (propertyName == "code")
    {
        return this->code;
    }
    else if (propertyName == "name")
    {
        return this->name;
    }
    else if (propertyName == "arrival")
    {
        return this->arrival;
    }
    else if (propertyName == "departure")
    {
        return this->departure;
    }
    else if (propertyName == "rating")
    {
        return this->rating;
    }
    else
    {
        throw invalid_argument("Propriedade desconhecida");
    }
}
