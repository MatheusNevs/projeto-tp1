#include <iostream>
#include <cctype>
#include "date.hpp"
#include "domain.hpp"

using namespace std;

bool Validate(string data) {
    bool validation = true;
    while ( validation == true ) {
        if (data[2] != '-' || data[5] != '-' || data[8] != '-') {
            validation = false;
        } else { 
            data.erase(2,1);
            data.erase(4,1);
            data.erase(6,1);
        }
    }
    for (char c : data) {
        if (!isdigit(c)) {
            validation = false;
        }
    }
    return validation;
}

Date::Date() : data("") {}
