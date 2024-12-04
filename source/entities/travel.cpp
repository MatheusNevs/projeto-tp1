#include "../../include/entities/travel.hpp"

Travel::Travel(const Code &code, const Name &name, const Date &startDate, const Date &endDate, const Money &totalCost, const Rating &rating)
    : code(code), name(name), startDate(startDate), endDate(endDate), totalCost(totalCost), rating(rating) {}

void Travel::set(const Domain &domain, string propertyName)
{
    if (propertyName == "code")
    {
        this->code = static_cast<const Code &>(domain);
    }
    else if (propertyName == "name")
    {
        this->name = static_cast<const Name &>(domain);
    }
    else if (propertyName == "startDate")
    {
        this->startDate = static_cast<const Date &>(domain);
    }
    else if (propertyName == "endDate")
    {
        this->endDate = static_cast<const Date &>(domain);
    }
    else if (propertyName == "totalCost")
    {
        this->totalCost = static_cast<const Money &>(domain);
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

const Domain &Travel::get(const string propertyName) const
{
    if (propertyName == "code")
    {
        return this->code;
    }
    else if (propertyName == "name")
    {
        return this->name;
    }
    else if (propertyName == "startDate")
    {
        return this->startDate;
    }
    else if (propertyName == "endDate")
    {
        return this->endDate;
    }
    else if (propertyName == "totalCost")
    {
        return this->totalCost;
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
