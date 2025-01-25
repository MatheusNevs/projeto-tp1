#ifndef PRESENTATION_INTERFACE_H
#define PRESENTATION_INTERFACE_H

#include "../domains/code.hpp"

/**
 * @class PresentationInterface
 * @brief Interface abstrata para a apresentação de código.
 *
 * Esta classe fornece uma interface para a apresentação de código,
 * exigindo que as classes derivadas implementem o método execute.
 */
class PresentationInterface
{
protected:
  Code &userCode;

public:
  PresentationInterface(Code &userCode) : userCode(userCode) {}
  virtual void execute(Code &userCode) = 0;
  virtual ~PresentationInterface() {};
};

#endif // PRESENTATION_INTERFACE_H