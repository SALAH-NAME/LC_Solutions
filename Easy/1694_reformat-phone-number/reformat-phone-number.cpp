#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string reformatNumber(std::string number)
  {
    std::string digits;
    for (char c : number)
    {
      if (isdigit(c))
        digits.push_back(c);
    }

    std::string result;
    int n = digits.size();
    int i = 0;

    while (n > 0)
    {
      if (n > 4)
      {
        result.append(digits.substr(i, 3));
        result.push_back('-');
        i += 3;
        n -= 3;
      }
      else if (n == 4)
      {
        result.append(digits.substr(i, 2));
        result.push_back('-');
        result.append(digits.substr(i + 2, 2));
        n = 0;
      }
      else
      {
        result.append(digits.substr(i, n));
        n = 0;
      }
    }

    return result;
  }
};

int main()
{
  std::vector<std::string> tests = {
    "1-23-45 6",
    "123 4-567",
    "123 4-5678",
  };

  for (auto& s : tests)
  {
    std::cout << "---\nnumber: '" << s << "'\nreformatNumber: '";
    std::cout << Solution().reformatNumber(s) << "'" << std::endl;
  }
  return 0;
}
