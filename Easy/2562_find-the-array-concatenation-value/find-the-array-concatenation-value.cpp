#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  long long findTheArrayConcVal(std::vector<int>& nums)
  {
    long long ans = 0;
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
      std::string combined = std::to_string(nums[i]) + std::to_string(nums[j]);
      ans += std::stoll(combined);
      i++;
      j--;
    }

    if (i == j)
    {
      ans += nums[i];
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
    {{7,52,2,4}},
    {{5,14,13,8,12}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nfindTheArrayConcVal: ";
    std::cout << Solution().findTheArrayConcVal(n) << std::endl;
  }
  return 0;
}
