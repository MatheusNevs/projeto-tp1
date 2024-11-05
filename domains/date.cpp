#include <iostream>
#include <cctype>
#include "date.hpp"
#include "domain.hpp"

using namespace std;

Date::Date() : data("") {}

bool certify (int day,int month,bool isBis) {
    int largeMonth[7] = {1,3,5,7,8,10,12};
    bool validation = true;
    if (day >= 29) {
        if (month == 2) {
            if (!isBis) {
                validation = false;
            }
        } else if (day > 30){
            bool isLarge = false;
            for (int m : largeMonth) {
                if (month == m) {
                    isLarge = true;
                }
            }
            if (!isLarge) {
                validation = false;
            }
        }
    }
    return validation;
}

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
    int day = stoi(data.substr(0, 2));
    int month = stoi(data.substr(2, 2));
    int year = stoi(data.substr(4, 2));
    if (day >= 1 && day<= 31) {
        if (month >= 1 && month <= 12) {
            if (year >= 0 && year <= 99) {
                bool isBis = false;
                if (year%4 == 0) {
                    isBis = true;
                }
                validation = certify(day,month,isBis);
            }
        }
    } else {
        validation = false;
    }
    return validation;
}
