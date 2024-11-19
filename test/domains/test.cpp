#include "./test.hpp"

// Implementação do construtor UnitTest
UnitTest::UnitTest(const std::string &validValue, const std::string &invalidValue, Domain *domain)
    : validValue(validValue), invalidValue(invalidValue), domain(domain), success(true) {}

// Implementação do método test
void UnitTest::test()
{
  try
  {
    // Testa com valor válido
    domain->setValue(validValue);
  }
  catch (...)
  {
    success = false;
    std::cout << RED << "Falha: Valor válido '" << validValue << "' gerou erro.\n"
              << RESET;
  }

  try
  {
    // Testa com valor inválido
    domain->setValue(invalidValue);
    success = false;
    std::cout << RED << "Falha: Valor inválido '" << invalidValue << "' não gerou erro.\n"
              << RESET;
  }
  catch (...)
  {
    // Comportamento esperado para valor inválido
  }
}

// Retorna o sucesso do teste
bool UnitTest::getSuccess() const
{
  return success;
}

// Retorna a descrição do teste
std::string UnitTest::getDescription() const
{
  return "Testando domínio com valor válido '" + validValue + "' e valor inválido '" + invalidValue + "'.";
}

// Implementação do construtor GroupTest
GroupTest::GroupTest(const std::string &name, const std::vector<UnitTest> &tests)
    : name(name), tests(tests) {}

// Executa todos os testes do grupo
void GroupTest::runTests()
{
  std::cout << "Executando testes no grupo: " << name << "\n";

  size_t passedCount = 0; // Contador de testes aprovados

  for (size_t i = 0; i < tests.size(); ++i)
  {
    std::cout << "\nTeste " << i + 1 << ": " << tests[i].getDescription() << "\n";
    tests[i].test();

    if (tests[i].getSuccess())
    {
      std::cout << GREEN << "Teste " << i + 1 << " passou.\n"
                << RESET;
      passedCount++;
    }
    else
    {
      std::cout << RED << "Teste " << i + 1 << " falhou.\n"
                << RESET;
    }
  }

  std::cout << "\nFim dos testes do grupo: " << name << "\n";

  // Resumo no final
  std::cout << (passedCount == tests.size() ? GREEN : RED)
            << "Passaram: " << passedCount << " / " << tests.size() << RESET << "\n";
}
