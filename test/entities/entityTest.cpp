#include "./entityTest.hpp"

void EntityUnitTest::destroyEntityUnitTest() {
  delete entity;
}

void EntityUnitTest::test()
{
  try
  {
    this->entity->set(*this->domainTest, propertyName);
    if (this->entity->get(this->propertyName).getValue() != domainTest->getValue())
    {
      cout << RED << "Falha: Valor válido " << domainTest->getValue() << " não foi atribuído corretamente à entidade.\n"
           << RESET;
      success = false;
    }
  }
  catch (...)
  {
    success = false;
    cout << RED << "Falha: Valor válido " << domainTest->getValue() << " gerou erro.\n"
         << RESET;
  }
  
  // Chama método que destroi teste atual
  destroyEntityUnitTest();
}

string EntityUnitTest::getDescription() const
{
  return "Testando entidade com valor válido '" + this->domainTest->getValue() + "'.\n";
}
