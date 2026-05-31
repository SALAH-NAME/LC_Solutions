#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int countVowelSubstrings(std::string word)
  {
    return countAtMost(word, 5) - countAtMost(word, 4);
    return {};
  }
private:
  int countAtMost(const std::string& word, int k)
  {
    int left = 0, total_substrings = 0;
    std::unordered_map<char, int> vowel_counts;

    for (int right = 0; right < word.length(); ++right)
    {
      char r_char = word[right];
      if (!isVowel(r_char))
      {
        vowel_counts.clear();
        left = right + 1;
        continue;
      }
      vowel_counts[r_char]++;
      while (vowel_counts.size() > k)
      {
        char l_char = word[left];
        vowel_counts[l_char]--;
        if (vowel_counts[l_char] == 0)
        {
          vowel_counts.erase(l_char);
        }
        left++;
      }
      total_substrings += (right - left + 1);
    }
    return total_substrings;
  }
  bool isVowel(char ch)
  {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }
};

typedef struct testCase
{
  std::string w;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"aeiouu"},
    {"unicornarihan"},
    {"cuaieuouac"},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nword: '" << w << "'\ncountVowelSubstrings: ";
    std::cout << Solution().countVowelSubstrings(w) << std::endl;
  }
  return 0;
}
