// Classe implementada pelo aluno com matrícula 231025181

#include "../../include/entities/travel.hpp"

Travel::Travel(const Code &code, const Name &name, const Rating &rating)
    : code(code), name(name), rating(rating) {}

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
    else if (propertyName == "rating")
    {
        return this->rating;
    }
    else
    {
        throw invalid_argument("Propriedade desconhecida");
    }
}
