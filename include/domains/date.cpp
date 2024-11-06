#include <iostream>
#include <cctype>
#include "date.hpp"
#include "domain.hpp"

/**
 * @brief Constructs a Date object with an empty date string.
 */
Date::Date() : data("") {}

/**
 * @brief Verifies the day and month are within valid ranges, with special cases for leap years.
 * @param day The day component of the date.
 * @param month The month component of the date.
 * @param isBis A boolean that is true if the year is a leap year, false otherwise.
 * @return true if the day and month are valid, considering leap year rules; false otherwise.
 */
bool certify(int day, int month, bool isBis) {
    int largeMonth[7] = {1, 3, 5, 7, 8, 10, 12};
    bool validation = true;

    // Check for valid day in February and leap years
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

/**
 * @brief Validates the format and values of a given date string.
 * @param data The date string in "DD-MM-YY" format.
 * @return true if the date is valid in format and range, false otherwise.
 */
bool Date::Validate(const std::string& data) {
    // Check basic format requirements
    if (data.size() != 10 || data[2] != '-' || data[5] != '-' || data[8] != '-') {
        return false;
    }

    // Prepare the date string for parsing by removing hyphens
    std::string cleanData = data;
    cleanData.erase(2, 1);
    cleanData.erase(4, 1);
    cleanData.erase(6, 1);

    // Validate numeric content of the date
    for (char c : cleanData) {
        if (!isdigit(c)) {
            return false;
        }
    }

    // Extract day, month, and year as integers
    int day = std::stoi(cleanData.substr(0, 2));
    int month = std::stoi(cleanData.substr(2, 2));
    int year = std::stoi(cleanData.substr(4, 2));

    // Validate day, month, and year ranges
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0 || year > 99) {
        return false;
    }

    // Determine if the year is a leap year and validate further based on month length
    bool isBis = (year % 4 == 0);
    return certify(day, month, isBis);
}