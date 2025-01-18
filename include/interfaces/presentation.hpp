#ifndef PRESENTATION_INTERFACE_H
#define PRESENTATION_INTERFACE_H

#include "../domains/code.hpp"

class PresentationInterface
{
protected:
  Code *&userCode;

public:
  PresentationInterface(Code *&userCode) : userCode(userCode)
  {
  }
  virtual void execute(Code *&userCode) = 0;
};

#endif // PRESENTATION_INTERFACE_H