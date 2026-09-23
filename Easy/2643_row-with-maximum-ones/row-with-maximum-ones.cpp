#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat)
  {
    std::vector<int> ans = {0, 0};
    for (int i = 0; i < mat.size(); i++)
    {
      int cnt = 0;
      for (int x : mat[i])
      {
        if (x == 1)
        {
          cnt++;
        }
      }
      if (ans[1] < cnt)
      {
        ans[0] = i;
        ans[1] = cnt;
      }
    }
    return ans;
  }
};

void printV(const std::vector<int>& v)
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

void printM(const std::vector<std::vector<int>>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    printV(v[i]);
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> m;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{0,1},{1,0}}},
    {{{0,0,0},{0,1,1}}},
    {{{0,0},{1,1},{0,0}}},
  };

  for (auto& [m] : tests)
  {
    std::cout << "---\nmat: ";
    printM(m);
    std::cout << "\nrowAndMaximumOnes: ";
    printV(Solution().rowAndMaximumOnes(m));
    std::cout <<std::endl;
  }
  return 0;
}
