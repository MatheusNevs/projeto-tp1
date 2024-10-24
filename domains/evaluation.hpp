#ifndef evluation.hpp
#define evaluation.hpp

using namespace std;

class Evaluation {
    private:

        unsigned int rating: 3;

    public:

        Evaluation();

        inline unsigned int getRating();

        bool setRating(unsigned int);
};

#endif