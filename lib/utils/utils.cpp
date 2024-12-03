#include "utils.hpp"

vector<string> Utils::split(const string &str, const char *delimiter)
{
  vector<string> tokens;
  string token;
  for (char ch : str)
  {
    if (ch == *delimiter)
    {
      if (!token.empty())
      {
        tokens.push_back(token);
        token.clear();
      }
    }
    else
    {
      token += ch;
    }
  }
  if (!token.empty())
  {
    tokens.push_back(token);
  }
  return tokens;
}