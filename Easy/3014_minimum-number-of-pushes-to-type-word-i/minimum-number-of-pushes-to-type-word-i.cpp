#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
  int minimumPushes(std::string word)
  {
    int n = static_cast<int>(word.size());
    int pushes = 0;
    for (int i = 0; i < n; i++)
    {
      pushes += (i / 8) + 1;
    }
    return pushes;
  }
};

typedef struct testCase
{  
  std::string w;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"abcde"},
    {"xycdefghij"},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nword: " << w << "\nminimumPushes: ";
    std::cout << Solution().minimumPushes(w) << std::endl;
  }
  return 0;
}
