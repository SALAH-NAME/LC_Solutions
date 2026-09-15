#include <string>
#include <string_view>
#include <vector>
#include <iostream>

class Solution
{
public:
  int vowelStrings(std::vector<std::string>& words, int left, int right)
  {
    int count = 0;
    for (int i = left; i <= right; i++)
    {
      if (isVowel(words[i].front()) && isVowel(words[i].back()))
      {
        count++;
      }
    }
    return count;
  }
private:
  bool isVowel(char c)
  {
    static constexpr std::string_view vowels = "aeiou";
    return vowels.find(c) != std::string_view::npos;
  }
};

void printV(const std::vector<std::string>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << "< ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::string> w;
  int l;
  int r;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"are","amy","u"}, 0, 2},
    {{"hey","aeo","mu","ooo","artro"}, 1, 4},
  };

  for (auto& [w, l, r] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\nleft: " << l << ", right: " << r << "\nvowelStrings: ";
    std::cout << Solution().vowelStrings(w, l, r) << std::endl;
  }
  return 0;
}
