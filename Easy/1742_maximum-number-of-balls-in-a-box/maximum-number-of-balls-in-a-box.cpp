#include <vector>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
  int countBalls(int lowLimit, int highLimit)
  {
    std::unordered_map<int, int> boxCount;

    for (int i = lowLimit; i <= highLimit; ++i)
    {
      int sum = digitSum(i);
      boxCount[sum]++;
    }

    int maxBalls = 0;
    for (auto& [box, count] : boxCount)
    {
      if (count > maxBalls)
        maxBalls = count;
    }

    return maxBalls;
  }

private:
  int digitSum(int n)
  {
    int sum = 0;
    while (n > 0)
    {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
};

typedef struct testCase
{
  int l;
  int h;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {1, 10},
    {5, 15},
    {19, 28},
  };

  for (auto& [l, h] : tests)
  {
    std::cout << "---\nlowLimit: " << l << ", highLimit: " << h;
    std::cout << "\ncountBalls: " << Solution().countBalls(l, h);
    std::cout << std::endl;
  }
  return 0;
}
