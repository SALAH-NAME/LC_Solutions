#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2)
  {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    int answer1 = 0;
    int answer2 = 0;

    for (int x : nums1)
    {
      if (set2.count(x)) answer1++;
    }
    for (int x : nums2)
    {
      if (set1.count(x)) answer2++;
    }
    return {answer1, answer2};
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
  std::vector<int> n1;
  std::vector<int> n2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{2,3,2}, {1,2}},
    {{4,3,2,3,1}, {2,2,5,2,3,6}},
    {{3,4,2,3}, {1,5}},
  };

  for (auto& [n1, n2] : tests)
  {
    std::cout << "---\nn1: ";
    printV(n1);
    std::cout << ", n2: ";
    printV(n2);
    std::cout << "\nfindIntersectionValues: ";
    printV(Solution().findIntersectionValues(n1, n2));
    std::cout << std::endl;
  }
  return 0;
}
