#include <cctype>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool strongPasswordCheckerII(std::string password)
  {
    if (password.length() < 8) return false;
    int res = 0;
    std::string specials = "!@#$%^&*()-+";

    for (int i = 0; i < password.length(); ++i)
    {
      if (i > 0 && password[i] == password[i - 1]) return false;

      char c = password[i];
      if (std::islower(c)) res |= 1;
      else if (std::isupper(c)) res |= 2;
      else if (std::isdigit(c)) res |= 4;
      else if (specials.find(c) != std::string::npos) res |= 8;
    }

    return __builtin_popcount(res) == 4;
  }
};

typedef struct testCase
{
  std::string p;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"IloveLe3tcode!"},
    {"Me+You--IsMyDream"},
    {"1aB!"},
  };

  for (auto& [p] : tests)
  {
    std::cout << "---\npassword: " << p << "\nstrongPasswordCheckerII: ";
    std::cout << (Solution().strongPasswordCheckerII(p) ? "True" : "False");
    std::cout << std::endl;
  }
  return 0;
}
