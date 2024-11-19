#include "../../include/domains/domain.hpp"

// Definições de cores ANSI para saída colorida
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

class UnitTest
{
private:
  std::string validValue;
  std::string invalidValue;
  Domain *domain;
  bool success;

public:
  UnitTest(const std::string &validValue, const std::string &invalidValue, Domain *domain);
  void test();
  bool getSuccess() const;
  std::string getDescription() const;
};

class GroupTest
{
private:
  std::string name;
  std::vector<UnitTest> tests;

public:
  GroupTest(const std::string &name, const std::vector<UnitTest> &tests);
  void runTests();
};
