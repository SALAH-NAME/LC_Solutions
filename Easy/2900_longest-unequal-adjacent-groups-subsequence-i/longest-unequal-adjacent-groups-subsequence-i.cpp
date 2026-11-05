#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::string> getLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) 
  {
    std::vector<std::string> ans;
    int last_group = -1;

    for (int i = 0; i < groups.size(); i++)
    {
      if (groups[i] != last_group)
      {
        ans.push_back(words[i]);
        last_group = groups[i];
      }
    }
    return ans;
  }
};

template <typename T>
void printV(const std::vector<T>& v)
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
  std::vector<std::string> w;
  std::vector<int> g;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"c"}, {0}},
    {{"d"}, {1}},
  };

  for (auto& [w, g] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\ngroups: ";
    printV(g);
    std::cout << "\ngetLongestSubsequence: ";
    printV(Solution().getLongestSubsequence(w, g));
    std::cout << std::endl;
  }
  return 0;
}
