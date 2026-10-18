#include <sstream>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::string> splitWordsBySeparator(std::vector<std::string>& words, char separator)
  {
    std::vector<std::string> result;

    for (const std::string& word : words)
    {
      std::stringstream ss(word);
      std::string part;

      while (std::getline(ss, part, separator))
      {
        if (!part.empty())
        {
          result.push_back(part);
        }
      }
    }
    return result;
  }
};

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

typedef struct testCase
{
  std::vector<std::string> w;
  char s;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"one.two.three","four.five","six"}, '.'},
    {{"$easy$","$problem$"}, '$'},
    {{"|||"}, '|'},
  };

  for (auto& [w, s] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << ", separator: '" << s << "'\nsplitWordsBySeparator: ";
    printV(Solution().splitWordsBySeparator(w, s));
    std::cout << std::endl;
  }
  return 0;
}
