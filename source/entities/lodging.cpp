// Classe implementada pelo aluno com matrícula 231025207

#include "../../include/entities/lodging.hpp"

Lodging::Lodging(const Code &code, const Name &name, const Money &dailyRate, const Rating &rating)
    : code(code), name(name), dailyRate(dailyRate), rating(rating) {}

void Lodging::set(const Domain &domain, string propertyName)
{
    if (propertyName == "code")
    {
        this->code = static_cast<const Code &>(domain);
    }
    else if (propertyName == "name")
    {
        this->name = static_cast<const Name &>(domain);
    }
    else if (propertyName == "dailyRate")
    {
        this->dailyRate = static_cast<const Money &>(domain);
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

const Domain &Lodging::get(const string propertyName) const
{
    if (propertyName == "code")
    {
        return this->code;
    }
    else if (propertyName == "name")
    {
        return this->name;
    }
    else if (propertyName == "dailyRate")
    {
        return this->dailyRate;
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
