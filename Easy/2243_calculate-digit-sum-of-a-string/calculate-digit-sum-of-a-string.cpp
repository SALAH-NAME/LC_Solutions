#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string digitSum(std::string s, int k)
  {
    while (s.size() > k)
    {
      std::string next_s = "";

      for (int i = 0 ; i < s.size(); i += k)
      {
        std::string chunk = s.substr(i, k);

        int sum = 0;
        for (char c : chunk)
          sum += c - '0';
        next_s += std::to_string(sum);
      }
      s = next_s;
    }
    return s;
  }
};

typedef struct testCase
{
  std::string s;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"11111222223", 3},
    {"00000000", 3},
  };

  for (auto& [s, k] : tests)
  {
    std::cout << "---\ns= '" << s << "', k: " << k << "\ndigitSum: '";
    std::cout << Solution().digitSum(s, k) << "'" << std::endl;
  }
  return 0;
}
