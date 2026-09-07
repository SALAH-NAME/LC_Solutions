#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> separateDigits(std::vector<int>& nums)
  {
    std::vector<int> ans;

    for (int num : nums)
    {
      std::string s = std::to_string(num);
      for (char c : s)
      {
        ans.push_back(c - '0');
      }
    }
    return ans;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<int> n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{13,25,83,77}},
    {{7,1,3,9}},
  };

  for (auto& [n]: tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nseparateDigits: ";
    printV(Solution().separateDigits(n));
    std::cout << std::endl;
  }
  return 0;
}
