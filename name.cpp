#include "name.hpp"

using namespace std;

bool Name::validate (const string& name) {
    if (name.length() > 30 || name.empty()) {    //name vazio ou maior que 30 caracteres
        return false;
    }
    return true;
}

bool Name::setName (const string& name) {
    if (validate (name)) {                      
        return false;
    }
    value = name;
    return true;
}

string Name::getName() const {
    return value;
}