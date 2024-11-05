#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
private:
    std::string data;

public:
    bool Validate(const std::string&);
};

bool certify(int day, int month, bool isBis);

#endif
