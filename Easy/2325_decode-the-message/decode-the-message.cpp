#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::string decodeMessage(std::string key, std::string message)
  {
    std::unordered_map<char, char> mapping;
    mapping[' '] = ' ';

    char curr = 'a';
    for (char c : key)
    {
      if (c != ' ' && mapping.find(c) == mapping.end())
      {
        mapping[c] = curr++;
      }
    }

    std::string decoded = "";
    for (char c : message)
    {
      decoded += mapping[c];
    }
    return decoded;
  }
};

typedef struct testCase
{
  std::string k;
  std::string m;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv"},
    {"eljuxhpwnyrdgtqkviszcfmabo", "zwx hnfx lqantp mnoeius ycgk vcnjrdb"},
  };

  for (auto& [k, m] : tests)
  {
    std::cout << "---\nkey: '" << k << "'\nmessage: '" << m << "'\n";
    std::cout << "decodeMessage: " << Solution().decodeMessage(k, m) << std::endl;
  }
  return 0;
}
