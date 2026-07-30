#include <map>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2)
  {
    std::map<int, int> weight_map;

    for (const auto& item : items1)
    {
      weight_map[item[0]] += item[1];
    }

    for (const auto& item : items2)
    {
      weight_map[item[0]] += item[1];
    }

    std::vector<std::vector<int>> result;
    for (const auto& pair : weight_map)
    {
      result.push_back({pair.first, pair.second});
    }
    return result;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size())
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
    if (i < v.size())
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> i1;
  std::vector<std::vector<int>> i2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{1,1},{4,5},{3,8}}, {{3,1},{1,5}}},
    {{{1,1},{3,2},{2,3}}, {{2,1},{3,2},{1,3}}},
    {{{1,3},{2,2}}, {{7,1},{2,2},{1,4}}},
  };

  for (auto& [i1, i2] : tests)
  {
    std::cout << "---\nitems1: ";
    printM(i1);
    std::cout << "\nitems2: ";
    printM(i2);
    std::cout << "\nmergeSimilarItems: ";
    printM(Solution().mergeSimilarItems(i1, i2));
    std::cout << std::endl;
  }
  return 0;
}
