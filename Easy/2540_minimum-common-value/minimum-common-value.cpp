#include <vector>
#include <iostream>

class Solution
{
public:
  int getCommon(std::vector<int>& nums1, std::vector<int>& nums2)
  {
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
      if (nums1[i] == nums2[j])
      {
        return nums1[i];
      }
      else if (nums1[i] < nums2[j])
      {
        i++;
      }
      else
      {
        j++;
      }
    }
    return -1;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (size_t i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

struct testCase
{
  std::vector<int> n1;
  std::vector<int> n2;
};

int main()
{
  std::vector<testCase> tests = {
    {{1, 2, 3}, {2, 4}},
    {{1, 2, 3, 6}, {2, 3, 4, 5}},
    {{1, 2, 3}, {4, 5, 6}}
  };

  for (auto& [n1, n2] : tests)
  {
    std::cout << "---\nnums1: ";
    printV(n1);
    std::cout << "\nnums2: ";
    printV(n2);
    std::cout << "\nMinimum Common: " << Solution().getCommon(n1, n2) << std::endl;
  }
  return 0;
}
