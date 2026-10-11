#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
  int maximumNumberOfStringPairs(std::vector<std::string>& words)
  {
    std::unordered_set<std::string> seen;
    int ans = 0;

    for (const std::string& word : words)
    {
      std::string rev = word;
      std::reverse(rev.begin(), rev.end());
      if (seen.count(rev))
      {
        ans++;
      }
      else
      {
        seen.insert(word);
      }
    }
    return ans;
  }
};

typedef struct testCase
{
  std::vector<std::string> w;
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
    {{"cd","ac","dc","ca","zz"}},
    {{"ab","ba","cc"}},
    {{"aa","ab"}},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\nmaximumNumberOfStringPairs: ";
    std::cout << Solution().maximumNumberOfStringPairs(w) << std::endl;
  }
  return 0;
}
