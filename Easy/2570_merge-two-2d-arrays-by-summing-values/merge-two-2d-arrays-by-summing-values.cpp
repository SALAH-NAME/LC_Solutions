#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2)
  {
    int ptr1 = 0, ptr2 = 0;
    int n1 = nums1.size(), n2 = nums2.size();
    std::vector<std::vector<int>> result;

    while (ptr1 < n1 && ptr2 < n2)
    {
      int id1 = nums1[ptr1][0], val1 = nums1[ptr1][1];
      int id2 = nums2[ptr2][0], val2 = nums2[ptr2][1];

      if (id1 == id2)
      {
        result.push_back({id1, val1 + val2});
        ptr1++;
        ptr2++;
      } else if (id1 < id2)
      {
        result.push_back({id1, val1});
        ptr1++;
      } else
      {
        result.push_back({id2, val2});
        ptr2++;
      }
    }

    while (ptr1 < n1)
    {
      result.push_back(nums1[ptr1++]);
    }

    while (ptr2 < n2)
    {
      result.push_back(nums2[ptr2++]);
    }

    return result;
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

void printM(const std::vector<std::vector<int>>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    printV(v[i]);
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> n1;
  std::vector<std::vector<int>> n2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{1,2},{2,3},{4,5}}, {{1,4},{3,2},{4,1}}},
    {{{2,4},{3,6},{5,5}}, {{1,3},{4,3}}},
  };

  for (auto& [n1, n2] : tests)
  {
    std::cout << "---\nnum1: ";
    printM(n1);
    std::cout << "\nnums2: ";
    printM(n2);
    std::cout << "\nmergeArrays: ";
    printM(Solution().mergeArrays(n1, n2));
    std::cout << std::endl;
  }
  return 0;
}
