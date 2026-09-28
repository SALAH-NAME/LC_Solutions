#include <vector>
#include <iostream>

class Solution
{
private:
  int getScore(const std::vector<int>& arr)
  {
    int total_score = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
      bool is_double = false;
      if ((i > 0 && arr[i - 1] == 10) || (i > 1 && arr[i - 2] == 10))
      {
        is_double = true;
      }

      if (is_double)
      {
        total_score += 2 * arr[i];
      }
      else
      {
        total_score += arr[i];
      }
    }
    return total_score;
  }
public:
  int isWinner(std::vector<int>& player1, std::vector<int>& player2)
  {
    int score1 = getScore(player1);
    int score2 = getScore(player2);

    if (score1 > score2)
    {
      return 1;
    }
    else if (score2 > score1)
    {
      return 2;
    }
    return 0;
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
  std::vector<int> p1;
  std::vector<int> p2;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{5,10,3,2}, {6,5,7,3}},
    {{3,5,7,6}, {8,10,10,2}},
    {{2,3}, {4,1}},
    {{1,1,1,10,10,10,10}, {10,10,10,10,1,1,1}},
  };

  for (auto& [p1, p2] : tests)
  {
    std::cout << "---\nplayer1: ";
    printV(p1);
    std::cout << "\nplayer2: ";
    printV(p2);
    std::cout << "\nisWinner: " << Solution().isWinner(p1, p2) << std::endl;
  }
  return 0;
}
