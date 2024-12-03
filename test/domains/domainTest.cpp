#include "./domainTest.hpp"

void DomainUnitTest::test()
{
  try
  {
    // Testa com valor válido
    domain->setValue(validValue);
    if (domain->getValue() != validValue)
      cout << RED << "Falha: Valor válido '" << validValue << "' não foi salvo.\n"
           << RESET;
  }
  catch (...)
  {
    success = false;
    cout << RED << "Falha: Valor válido '" << validValue << "' gerou erro.\n"
         << RESET;
  }

  try
  {
    // Testa com valor inválido
    domain->setValue(invalidValue);
    success = false;
    cout << RED << "Falha: Valor inválido '" << invalidValue << "' não gerou erro.\n"
         << RESET;
    if (domain->getValue() == invalidValue)
      cout << RED << "Falha: Valor inválido '" << invalidValue << "' foi salvo.\n"
           << RESET;
  }
  catch (...)
  {
    // Comportamento esperado para valor inválido
  }
  destroyDomainUnitTest();
}

string DomainUnitTest::getDescription() const
{
  return "Testando domínio com valor válido '" + this->validValue + "' e valor inválido '" + this->invalidValue + "'.";
}