#include "../domains/code.hpp"

class PresentationInterface
{
public:
  virtual void executar(Code userCode) = 0;
};