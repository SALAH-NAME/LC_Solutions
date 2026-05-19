#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  std::string reversePrefix(std::string word, char ch)
  {
    auto it = std::find(word.begin(), word.end(), ch);
    if (it != word.end())
    {
      std::reverse(word.begin(), it + 1);
    }
    return word;
  }
};

typedef struct testCase
{
  std::string w;
  char c;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"abcdefd", 'd'},
    {"xyxzxe", 'z'},
    {"abcd", 'z'},
  };

  for (auto& [w, c] : tests)
  {
    std::cout << "---\nword: '" << w << "', ch: '" << c << "'\nreversePrefix: '";
    std::cout << Solution().reversePrefix(w, c) << std::endl;
  }
  return 0;
}
