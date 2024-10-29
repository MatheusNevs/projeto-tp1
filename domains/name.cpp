#include "name.hpp"

bool Name::validate (string name) {
    if (name.length() > 30 || name.empty()) {    //name vazio ou maior que 30 caracteres
        return false;
    }
    return true;
}