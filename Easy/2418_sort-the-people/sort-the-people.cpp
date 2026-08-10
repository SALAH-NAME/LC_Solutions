#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights)
  {
    int n = names.size();

    std::vector<int> indices(n);
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(), [&](int i, int j){
        return heights[i] > heights[j];
        });

    std::vector<std::string> res;
    res.reserve(names.size());

    for (int i : indices)
    {
      res.push_back(names[i]);
    }
    return res;
  }
};

template <typename T>
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
  std::vector<std::string> n;
  std::vector<int> h;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{"Mary","John","Emma"}, {180,165,170}},
    {{"Alice","Bob","Bob"}, {155,185,150}},
  };

  for (auto& [n, h] : tests)
  {
    std::cout << "---\nnames: ";
    printV(n);
    std::cout << "\nheights: ";
    printV(h);
    std::cout << "\nsortPeople: ";
    printV(Solution().sortPeople(n, h));
    std::cout << std::endl;
  }
  return 0;
}
