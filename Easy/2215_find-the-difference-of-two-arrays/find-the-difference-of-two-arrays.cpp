#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2)
  {
    std::vector<std::vector<int>> result(2);
    std::unordered_set<int> n1(nums1.begin(), nums1.end());
    std::unordered_set<int> n2(nums2.begin(), nums2.end());

    for (int n : n1)
    {
      if (n2.find(n) == n2.end())
        result[0].push_back(n);
    }
    for (int n : n2)
    {
      if (n1.find(n) == n1.end())
        result[1].push_back(n);
    }
    return result;
  }
};

typedef struct testCase
{
  std::vector<int> n1;
  std::vector<int> n2;
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

void printMat(const std::vector<std::vector<int>>& m)
{
  std::cout << "{";
  for (int i = 0; i < m.size(); i++)
  {
    printV(m[i]);
    if (i < m.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

int main()
{
  std::vector<testCase> tests = {
    {{1,2,3}, {2,4,6}},
    {{1,2,3,3}, {1,1,2,2}},
  };

  for (auto& [n1, n2] : tests)
  {
    std::cout << "---\nnums1: ";
    printV(n1);
    std::cout << ", nums2: ";
    printV(n2);
    std::cout << "\nfindDifference: ";
    printMat(Solution().findDifference(n1, n2));
    std::cout << std::endl;
  }
  return 0;
}
