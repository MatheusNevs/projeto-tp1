#ifndef EVALUATION_HPP
#define EVALUATION_HPP

#include <string>

/**
 * @class Evaluation
 * @brief Manages and validates an evaluation rating, ensuring it falls within an acceptable range.
 */
class Evaluation {
private:
    unsigned int rating : 3; /**< Stores the rating as a 3-bit unsigned integer */

public:
    /**
     * @brief Default constructor that initializes the rating to 0.
     */
    Evaluation();
    
    /**
     * @brief Validates and sets the rating based on a given string input.
     * @param newRating A string representing the new rating, expected to be a number between "0" and "5".
     * @return true if the rating is within the valid range (0-5); false otherwise.
     */
    bool Validate(const std::string& newRating);
};

#endif // EVALUATION_HPP
