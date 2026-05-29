#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string kthDistinct(std::vector<std::string>& arr, int k)
  {
    std::unordered_map<std::string, int> freq;
    for (auto& s : arr)
      freq[s]++;

    int count = 0;
    for (auto& s : arr)
    {
      if (freq[s] == 1)
      {
        count++;
        if (count == k)
          return s;
      }
    }
    return "";
  }
};

typedef struct testCase
{
  std::vector<std::string> a;
  int k;
} testCase;

void printV(const std::vector<std::string>& v)
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
    {{"d","b","c","b","c","a"}, 2},
    {{"aaa","aa","a"}, 1},
    {{"a","b","a"}, 3},
  };

  for (auto& [a, k] : tests)
  {
    std::cout << "---\narr: ";
    printV(a);
    std::cout << ", k: " << k << "\nkthDistinct: '";
    std::cout << Solution().kthDistinct(a, k) << "'" << std::endl;
  }
  return 0;
}
