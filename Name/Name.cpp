#include "Name.hpp"

using namespace std;

bool Name::validate (const string& name) {
    if (name.length() > 30 || name.empty()) {    //name vazio ou maior que 30 caracteres
        return false;
    }
    return true;
}

bool Name::setName (const string& name) {
    if (validate (name)) {                      
        value = name;
        return true;
    }
    return false;
}

string Name::getName() const {
    return value;
}
