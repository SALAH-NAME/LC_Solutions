#include <cmath>
#include <queue>
#include <vector>
#include <iostream>

class Solution
{
public:
  long long pickGifts(std::vector<int>& gifts, int k)
  {
    std::priority_queue<int> maxHeap(gifts.begin(), gifts.end());

    for (int i = 0; i < k; i++)
    {
      int largest = maxHeap.top();
      maxHeap.pop();

      int reduced = std::floor(std::sqrt(largest));
      maxHeap.push(reduced);
    }

    long long totalGifts = 0;
    while (!maxHeap.empty())
    {
      totalGifts += maxHeap.top();
      maxHeap.pop();
    }
    return totalGifts;
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

typedef struct testCase
{
  std::vector<int> g;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{25,64,9,4,100}, 4},
    {{1,1,1,1}, 4},
  };

  for (auto& [g, k] : tests)
  {
    std::cout << "---\ngifts: ";
    printV(g);
    std::cout << "\nk: " << k << "\npickGifts: ";
    std::cout << Solution().pickGifts(g, k) << std::endl;
  }
  return 0;
}
