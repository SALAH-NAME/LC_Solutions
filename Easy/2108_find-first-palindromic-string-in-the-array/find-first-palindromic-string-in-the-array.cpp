#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string firstPalindrome(std::vector<std::string>& words)
  {
    for (auto& w : words)
    {
      if (isPalindrome(w))
      {
        return w;
      }
    }
    return "";
  }
private:
  bool isPalindrome(std::string& w)
  {
    int i = 0;
    int j = w.size() - 1;
    while (i < j)
    {
      if (w[i] != w[j])
        return false;
      i++;
      j--;
    }
    return true;
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
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"abc","car","ada","racecar","cool"}},
    {{"notapalindrome","racecar"}},
    {{"def","ghi"}},
  };

  for (auto& [w] : tests)
  {
    std::cout << "---\nwords: ";
    printV(w);
    std::cout << "\nfirstPalindrome: '";
    std::cout << Solution().firstPalindrome(w) << "'" << std::endl;
  }
}
