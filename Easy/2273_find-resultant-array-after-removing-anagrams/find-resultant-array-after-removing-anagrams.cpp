#include <vector>
#include <string>
#include <iostream>

class Solution
{
private:
  std::vector<int> getFreq(const std::string& s)
  {
    std::vector<int> freq(26, 0);
    for (char c : s)
    {
      freq[c - 'a']++;
    }
    return freq;
  }
public:
  std::vector<std::string> removeAnagrams(std::vector<std::string>& words)
  {
    std::vector<std::string> ans;

    for (std::string& word : words)
    {
      if (ans.empty() || getFreq(word) != getFreq(ans.back()))
      {
        ans.push_back(word);
      }
    }
    return ans;
  }
};

typedef struct testCase
{
  std::vector<std::string> w;
} testCase;

void printV(const std::vector<std::string>& w)
{
  std::cout << "{";
  for (int i = 0; i < w.size(); i++)
  {
    std::cout << w[i];
    if (i < w.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

int main()
{
  std::vector<testCase> tests = {
    {{"abba","baba","bbaa","cd","cd"}},
    {{"a","b","c","d","e"}},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\nremoveAnagrams: ";
    printV(Solution().removeAnagrams(w));
    std::cout << std::endl;
  }
  return 0;
}
