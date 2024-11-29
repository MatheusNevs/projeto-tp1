#include "../../include/domains/duration.hpp"

void Duration::validate(string value)
{
    int duration = stoi(value);
    if (duration < minDuration || duration > maxDuration)
    {
        throw invalid_argument("Argumento invalido.");
    }
}
