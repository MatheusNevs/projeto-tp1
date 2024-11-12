#include "domain.hpp"

class Duration : public Domain
{
private:
    static const int minDuration = 0;
    static const int maxDuration = 360;

    bool validate(string value) override;

public:
    Duration(string value);
};

inline Duration::Duration(string value) : Domain(value) {}
