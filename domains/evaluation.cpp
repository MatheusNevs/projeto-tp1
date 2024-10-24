#include <iostream>
#include "evaluation.hpp"
#include "domain.hpp"

using namespace std;

Evaluation::Evaluation() : rating(0) {}

bool Evaluation::setRating( unsigned int newRating) {
        if ( newRating >= 0 && newRating <= 5) {
            rating = newRating;
        } else {
            cout << "Error: Rating must be between 0 and 5\n";
            return false;
        }
        return true;
    }

unsigned int Evaluation::getRating() {
    return rating;
}
