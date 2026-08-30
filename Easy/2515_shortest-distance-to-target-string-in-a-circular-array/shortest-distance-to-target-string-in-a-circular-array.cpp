#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int closestTarget(std::vector<std::string>& words, std::string target, int startIndex)
  {
    int n = words.size();
    int ans = n;

    for (int i = 0; i < n; i++)
    {
      if (words[i] == target)
      {
        int dist = std::abs(i - startIndex);
        ans = std::min({ans, dist, n - dist});
      }
    }
    return ans == n ? -1 : ans;
  }
};

typedef struct testCase
{
  std::vector<std::string> w;
  std::string t;
  int s;
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
    {{"hello","i","am","leetcode","hello"}, "hello", 1},
    {{"a","b","leetcode"}, "leetcode", 0},
    {{"i","eat","leetcode"}, "ate", 0},
  };

  for (auto& [w, t, s] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << ", target: '" << t << "', startIndex: " << s ;
    std::cout << "\nclosestTarget: " << Solution().closestTarget(w, t, s);
    std::cout << std::endl;
  }
  return 0;
}
