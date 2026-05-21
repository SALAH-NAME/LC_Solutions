#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int finalValueAfterOperations(std::vector<std::string>& operations)
  {
    int x = 0;
    for (auto& o : operations)
    {
      if (o[1] == '+') 
        x++;
      else
        x--;
    }
    return x;
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
  std::vector<std::string> o;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"--X","X++","X++"}},
    {{"++X","++X","X++"}},
    {{"X++","++X","--X","X--"}},
  };

  for (auto& [o] : tests)
  {
    std::cout << "---\noperations: ";
    printV(o);
    std::cout << "\nfinalValueAfterOperations: ";
    std::cout << Solution().finalValueAfterOperations(o) << std::endl;
  }
  return 0;
}
