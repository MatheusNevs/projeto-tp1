#include <iostream>
#include <cctype>
#include "date.hpp"
#include "domain.hpp"

using namespace std;

Date::Date() : data("") {}

bool certify(int day, int month, bool isBis) {
    int largeMonth[7] = {1, 3, 5, 7, 8, 10, 12};
    bool validation = true;

    if (day >= 29) {
        if (month == 2) {
            if (!isBis) {
                validation = false;
            }
        } else if (day > 30) {
            bool isLarge = false;
            for (int m : largeMonth) {
                if (month == m) {
                    isLarge = true;
                    break;
                }
            }
            if (!isLarge) {
                validation = false;
            }
        }
    }
    return validation;
}

bool Date::Validate(const string& data) {
    if (data.size() != 10 || data[2] != '-' || data[5] != '-' || data[8] != '-') {
        return false;
    }

    std::string cleanData = data;
    cleanData.erase(2, 1);
    cleanData.erase(4, 1);
    cleanData.erase(6, 1);

    for (char c : cleanData) {
        if (!isdigit(c)) {
            return false;
        }
    }

    int day = std::stoi(cleanData.substr(0, 2));
    int month = std::stoi(cleanData.substr(2, 2));
    int year = std::stoi(cleanData.substr(4, 2));

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0 || year > 99) {
        return false;
    }

    bool isBis = (year % 4 == 0);
    return certify(day, month, isBis);
}