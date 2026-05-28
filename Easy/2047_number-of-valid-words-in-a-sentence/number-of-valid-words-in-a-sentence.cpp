#include <cctype>
#include <cstddef>
#include <string_view>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int countValidWords(std::string sentence)
  {
    int count = 0;
    std::string_view sv(sentence);
    size_t start = 0;
    size_t end = 0;
    while ((start = sv.find_first_not_of(' ', end)) != std::string_view::npos)
    {
      end = sv.find_first_of(' ', start);
      if (isValid(sv.substr(start, end - start)))
        count++;
    }
    return count;
  }
private:
  bool isValid(std::string_view word)
  {
    int hyphenCount = 0;
    int n = word.length();

    for (int i = 0; i < n; ++i)
    {
      char c = word[i];
      if (std::isdigit(c)) return false;
      if (c == '-')
      {
        if (++hyphenCount > 1) return false;
        if (i == 0 || i == n - 1 || !std::islower(word[i-1]) || !std::islower(word[i+1]))
          return false;
      }
      if (c == '!' || c == '.' || c == ',')
        if (i != n - 1) return false;
    }
    return true;
  }
};

typedef struct testCase
{
  std::string s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"cat and  dog"},
    {"!this  1-s b8d!"},
    {"alice and  bob are playing stone-game10"},
  };

  for (auto& [s] : tests)
  {
    std::cout << "---\nsentence: '" << s << "'\ncountValidWords: ";
    std::cout << Solution().countValidWords(s) << std::endl;
  }
  return 0;
}
