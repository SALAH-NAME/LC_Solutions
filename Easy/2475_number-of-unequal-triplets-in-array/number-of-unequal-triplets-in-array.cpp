#include <vector>
#include <iostream>

class Solution
{
public:
  int unequalTriplets(std::vector<int>& nums)
  {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k])
          {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};

typedef struct testCase
{
  std::vector<int> n;
} testCase;

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

int main()
{
  std::vector<testCase> tests = {
    {{4,4,2,4,3}},
    {{1,1,1,1,1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nunequalTriplets: " << Solution().unequalTriplets(n) << std::endl;
  }
  return 0;
}
