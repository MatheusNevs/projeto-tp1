#include <iostream>
#include "evaluation.hpp"

using namespace std;

Evaluation::Evaluation() : rating(0) {}

bool Evaluation::Validate( string newRating ) {
    int intNewRating;
    unsigned int UnsignedNewRating;
    int intNewRating = std::stoi( newRating );
    unsigned int UnsignedNewRating = static_cast<unsigned int>(intNewRating);
    if ( UnsignedNewRating >= 0 && UnsignedNewRating <= 5) {
        rating = UnsignedNewRating;
    } else {
        cout << "Error: Rating must be between 0 and 5\n";
        return false;
    }
    return true;
}
