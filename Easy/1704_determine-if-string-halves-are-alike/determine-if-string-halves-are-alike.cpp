#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

class Solution
{
public:
  bool halvesAreAlike(std::string s)
  {
    std::unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int n = s.size();
    int half = n / 2;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < half; i++)
    {
      if (vowels.count(s[i])) count1++;
    }
    for (int i = half; i < n; i++)
    {
      if (vowels.count(s[i])) count2++;
    }
    return count1 == count2;
  }
};

int main()
{
  std::vector<std::string> tests = {
    "book",
    "textbook",
  };

  for (auto& s : tests)
  {
    std::cout << "---\ns: '" << s << "'\nhalvesAreAlike: ";
    std::cout << (Solution().halvesAreAlike(s) ? "True" : "False") << std::endl;
  }
  return 0;
}
