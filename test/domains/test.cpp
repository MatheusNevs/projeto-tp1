#include "./test.hpp"

UnitTest::UnitTest(const string &validValue, const string &invalidValue, Domain *domain)
    : validValue(validValue), invalidValue(invalidValue), domain(domain), success(true) {}


void UnitTest::test()
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
}


bool UnitTest::getSuccess() const
{
  return success;
}


string UnitTest::getDescription() const
{
  return "Testando domínio com valor válido '" + validValue + "' e valor inválido '" + invalidValue + "'.";
}


GroupTest::GroupTest(const string &name, const vector<UnitTest> &tests)
    : name(name), tests(tests) {}


void GroupTest::runTests()
{
  cout << "\n" << "Executando testes no grupo: " << name << "\n";

  size_t passedCount = 0; // Contador de testes aprovados

  for (size_t i = 0; i < tests.size(); ++i)
  {
    cout << "\nTeste " << i + 1 << ": " << tests[i].getDescription() << "\n";
    tests[i].test();

    if (tests[i].getSuccess())
    {
      cout << GREEN << "Teste " << i + 1 << " passou.\n"
           << RESET;
      passedCount++;
    }
    else
    {
      cout << RED << "Teste " << i + 1 << " falhou.\n"
           << RESET;
    }
  }

  cout << "\nFim dos testes do grupo: " << name << "\n";

  // Resumo no final
  cout << (passedCount == tests.size() ? GREEN : RED)
       << "Passaram: " << passedCount << " / " << tests.size() << RESET << "\n";
}
