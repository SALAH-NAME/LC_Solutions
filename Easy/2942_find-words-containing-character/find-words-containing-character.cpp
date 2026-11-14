#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findWordsContaining(std::vector<std::string>& words, char x)
  {
    std::vector<int> result;

    for (int i = 0; i < words.size(); i++)
    {
      if (words[i].find(x) != std::string::npos)
      {
        result.push_back(i);
      }
    }
    return result;
  }
};

template<typename T>
void printV(const std::vector<T>& v)
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
  char x;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"leet","code"}, 'e'},
    {{"abc","bcd","aaaa","cbc"}, 'a'},
    {{"abc","bcd","aaaa","cbc"}, 'z'},
  };

  for (auto& [w, x] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << ", x: '" << x << "'\nfindWordsContaining: ";
    printV(Solution().findWordsContaining(w, x));
    std::cout << std::endl;
  }
  return 0;
}
