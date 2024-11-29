#include "./entityTest.hpp"

void EntityUnitTest::test()
{
  this->entity->set(*this->domainTest);
  if (this->entity->get(this->propertyName).getValue() != domainTest->getValue())
    success = false;
}

string EntityUnitTest::getDescription() const
{
  return "Testando entidade com valor válido '" + this->domainTest->getValue() + "'.";
}
