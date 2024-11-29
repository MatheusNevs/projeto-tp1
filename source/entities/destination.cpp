#include "../../include/entities/destination.hpp"
#include <typeinfo> // Necessário para typeid()

Destination::Destination(const Code &code, const Name &name, const Date &arrival, const Date &departure, const Rating &rating)
    : code(code), name(name), arrival(arrival), departure(departure), rating(rating) {}

void Destination::set(const Domain &domain)
{
    // Verificando o tipo de 'domain' diretamente pelo nome da classe
    if (typeid(domain) == typeid(Code))
    {
        this->code = static_cast<const Code &>(domain); // Atribui diretamente, sem necessidade de propertyName
    }
    else if (typeid(domain) == typeid(Name))
    {
        this->name = static_cast<const Name &>(domain);
    }
    else if (typeid(domain) == typeid(Date))
    {
        this->arrival = static_cast<const Date &>(domain); // Ou qualquer outra propriedade do destino
        this->departure = static_cast<const Date &>(domain);
    }
    else if (typeid(domain) == typeid(Rating))
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
