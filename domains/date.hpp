#ifndef DATE_HPP
#define DATE_HPP

#include <string>

/**
 * @class Date
 * @brief A class that represents a date and provides validation functionality.
 */
class Date {
private:
    std::string data; /**< Stores the date as a string */

public:
    /**
     * @brief Default constructor for Date class.
     */
    Date();

    /**
     * @brief Validates the date format and ensures it falls within valid day, month, and year ranges.
     * @param data The date string in the format "DD-MM-YY".
     * @return true if the date is valid, false otherwise.
     */
    bool Validate(const std::string& data);
};

/**
 * @brief Helper function to check if a given day and month are valid, including checks for leap years.
 * @param day The day component of the date.
 * @param month The month component of the date.
 * @param isBis A boolean indicating if the year is a leap year.
 * @return true if the date is valid within the constraints, false otherwise.
 */
bool certify(int day, int month, bool isBis);

#endif  // DATE_HPP
