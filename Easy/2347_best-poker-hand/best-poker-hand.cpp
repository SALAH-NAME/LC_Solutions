#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::string bestHand(std::vector<int>& ranks, std::vector<char>& suits)
  {
    std::unordered_set<char> unique_suits(suits.begin(), suits.end());
    if (unique_suits.size() == 1) return "Flush";

    std::unordered_map<int, int> rank_counts;
    int max_freq = 0;
    for (int rank : ranks)
    {
      rank_counts[rank]++;
      max_freq = std::max(max_freq, rank_counts[rank]);
    }

    if (max_freq >= 3) return "Three of a Kind";
    if (max_freq == 2) return "Pair";
    return "High Card";
  }
};

typedef struct testCase
{
  std::vector<int> r;
  std::vector<char> s;
} testCase;

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

int main()
{
  std::vector<testCase> tests = {
    {{13,2,3,1,9}, {'a','a','a','a','a'}},
    {{4,4,2,4,4}, {'d','a','a','b','c'}},
    {{10,10,2,12,9}, {'a','b','c','a','d'}},
  };

  for (auto& [r, s] : tests)
  {
    std::cout << "---\nranks: ";
    printV(r);
    std::cout << "\nsuits: ";
    printV(s);
    std::cout << "\nbestHand: ";
    std::cout << Solution().bestHand(r, s) << std::endl;
  }
  return 0;
}
