#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findEvenNumbers(std::vector<int>& digits)
  {
    int freq[10] = {0};
    for (int n : digits)
      freq[n]++;

    std::vector<int> result;
    for (int i = 100; i < 999; i+=2)
    {
      int d1 = i / 100;
      int d2 = (i / 10) % 10;
      int d3 = i % 10;

      freq[d1]--;
      freq[d2]--;
      freq[d3]--;
      if (freq[d1] >= 0 && freq[d2] >= 0 && freq[d3] >= 0)
        result.push_back(i);

      freq[d1]++;
      freq[d2]++;
      freq[d3]++;
    }
    return result;
  }
};

typedef struct testCase
{
  std::vector<int> d;
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
    {{2,1,3,0}},
    {{2,2,8,8,2}},
    {{3,7,5}},
  };

  for (auto& [d] : tests)
  {
    std::cout << "---\ndigits: ";
    printV(d);
    std::cout << "\nfindEvenNumbers: ";
    printV(Solution().findEvenNumbers(d));
    std::cout << std::endl;
  }
  return 0;
}
