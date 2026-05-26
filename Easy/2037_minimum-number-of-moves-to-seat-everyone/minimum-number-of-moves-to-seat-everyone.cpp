#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students)
  {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());

    int moves = 0;
    for (int i = 0; i < seats.size(); i++)
    {
      moves += std::abs(seats[i] - students[i]);
    }
    return moves;
  }
};

typedef struct testCase
{
  std::vector<int> se;
  std::vector<int> st;
} testCase;

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

int main()
{
  std::vector<testCase> tests = {
    {{3,1,5}, {2,7,4}},
    {{4,1,5,9}, {1,3,2,6}},
    {{2,2,6,6}, {1,3,2,6}},
  };

  for (auto& [se, st] : tests)
  {
    std::cout << "---\nseats: ";
    printV(se);
    std::cout << ", students: ";
    printV(st);
    std::cout << "\nminMovesToSeat: ";
    std::cout << Solution().minMovesToSeat(se, st) << std::endl;
  }
  return 0;
}
