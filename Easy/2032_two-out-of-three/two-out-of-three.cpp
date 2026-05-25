#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3)
  {
    int freq[101] = {0};

    for (int x : nums1)
      freq[x] |= 1;
    for (int x : nums2)
      freq[x] |= 2;
    for (int x : nums3)
      freq[x] |= 4;

    std::vector<int> res;
    for (int i = 1; i < 101; i++)
    {
      if (__builtin_popcount(freq[i]) >= 2)
        res.push_back(i);
    }
    return res;
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
  std::vector<int> n3;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,1,3,2}, {2, 3}, {3}},
    {{3,1}, {2, 3}, {1, 2}},
    {{1,2,2}, {4, 3, 3}, {5}},
  };

  for (auto& [n1, n2, n3] : tests)
  {
    std::cout << "---\nnums1: ";
    printV(n1);
    std::cout << "\nnums2: ";
    printV(n2);
    std::cout << "\nnums3: ";
    printV(n3);
    std::cout << "\ntwoOutOfThree: ";
    printV(Solution().twoOutOfThree(n1, n2, n3));
    std::cout << std::endl;
  }
  return 0;
}
