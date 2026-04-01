#include <vector>
#include <iostream>

class Solution
{
public:
  bool check(std::vector<int>& nums)
  {
    int countBreaks = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      int next = nums[(i + 1) % n];
      if (nums[i] > next)
          countBreaks++;
      if (countBreaks > 1)
        return false;
    }
    return true;
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

int main()
{
  std::vector<std::vector<int>> tests = {
    {3,4,5,1,2},
    {2,1,3,4},
    {1,2,3},
  };

  for (auto& n : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\ncheck: ";
    std::cout << (Solution().check(n) ? "true" : "false") << std::endl;
  }
  return 0;
}
