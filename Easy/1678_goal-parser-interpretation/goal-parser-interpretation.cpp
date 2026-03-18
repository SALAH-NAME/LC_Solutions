#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string interpret(std::string command)
  {
    std::string result;
    for (size_t i = 0; i < command.size(); )
    {
      if (command[i] == 'G')
      {
        result += 'G';
        i++;
      }
      else if (command[i] == '(' && command[i+1] == ')')
      {
        result += 'o';
        i += 2;
      }
      else if (command[i] == '(' && command[i+1] == 'a')
      {
        result += "al";
        i += 4;
      }
    }
    return result;
  }
};

int main()
{
  std::vector<std::string> tests = {
    "G()(al)",
    "G()()()()(al)",
    "(al)G(al)()()G",
  };

  for (auto& c : tests)
  {
    std::cout << "---\ncommand: '" << c << "'\n interpret: '";
    std::cout << Solution().interpret(c) << "'" << std::endl;
  }
  return 0;
}
