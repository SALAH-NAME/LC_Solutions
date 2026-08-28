#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int similarPairs(std::vector<std::string>& words)
  {
    int ans = 0;
    std::unordered_map<int, int> cnt;

    for (const std::string& w : words)
    {
      int mask = 0;
      for (char c : w)
      {
        mask |= (1 << (c - 'a'));
      }
      ans += cnt[mask];
      cnt[mask]++;
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
    {{"aba","aabb","abcd","bac","aabc"}},
    {{"aabb","ab","ba"}},
    {{"nba","cba","dba"}},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\nsimilarPairs: ";
    std::cout << Solution().similarPairs(w) << std::endl;
  }
  return 0;
}
