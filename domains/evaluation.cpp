#include <iostream>
#include "evaluation.hpp"

/**
 * @brief Constructs an Evaluation object, initializing the rating to 0.
 */
Evaluation::Evaluation() : rating(0) {}

/**
 * @brief Validates a rating value and assigns it if within the range of 0 to 5.
 * 
 * Converts the rating from a string to an unsigned integer and checks that it falls 
 * within the valid range. If invalid, outputs an error message.
 * 
 * @param newRating The new rating value as a string.
 * @return true if the rating is valid and has been assigned; false otherwise.
 */
bool Evaluation::Validate(const std::string& newRating) {
    unsigned int unsignedNewRating = std::stoi(newRating);
    
    if (unsignedNewRating >= 0 && unsignedNewRating <= 5) {
        rating = unsignedNewRating;
    } else {
        std::cout << "Error: Rating must be between 0 and 5\n";
        return false;
    }
    return true;
}

