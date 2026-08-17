#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string oddString(std::vector<std::string>& words)
  {
    std::unordered_map<std::string, std::vector<std::string>> diff_map;

    for (const std::string& word : words)
    {
      std::string diff_key = "";
      for (int i = 0; i < word.length() - 1; i++)
      {
        int diff = (word[i + 1] - 'a') - (word[i] - 'a');
        diff_key += std::to_string(diff) + ",";
      }
      diff_map[diff_key].push_back(word);
    }

    for (const auto& pair : diff_map)
    {
      if (pair.second.size() == 1)
      {
        return pair.second[0];
      }
    }
    return "";
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
    {{"adc","wzy","abc"}},
    {{"aaa","bob","ccc","ddd"}},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\noddString: ";
    std::cout << "'" << Solution().oddString(w) << "'" << std::endl;
  }
  return 0;
}
