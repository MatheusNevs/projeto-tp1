#ifndef evluation.hpp
#define evaluation.hpp
#include "domain.hpp"

using namespace std;

class Evaluation {
    private:
        unsigned int rating: 3;

    public:
        Evaluation();
        
        bool Validate(string);
};

#endif