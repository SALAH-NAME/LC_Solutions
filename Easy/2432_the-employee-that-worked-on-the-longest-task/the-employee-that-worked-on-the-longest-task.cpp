#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
  int hardestWorker(int n, std::vector<std::vector<int>>& logs)
  {
    int ans = logs[0][0];
    int max_time = logs[0][1];
    int last_time = max_time;

    for (int i = 1; i < logs.size(); i++)
    {
      int emp_id = logs[i][0];
      int leave_time = logs[i][1];
      int duration = leave_time - last_time;
      last_time = leave_time;

      if (duration > max_time)
      {
        max_time = duration;
        ans = emp_id;
      }
      else if (duration == max_time)
      {
        ans = std::min(ans, emp_id);
      }
    }
    return ans;
  }
};

typedef struct testCase
{
  int n;
  std::vector<std::vector<int>> l;
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

void printM(const std::vector<std::vector<int>>& m)
{
  std::cout << "{";
  for (int i = 0; i < m.size(); i++)
  {
    printV(m[i]);
    if (i < m.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

int main()
{
  std::vector<testCase> tests = {
    {10, {{0,3},{2,5},{0,9},{1,15}}},
    {26, {{1,1},{3,7},{2,12},{7,17}}},
    {2, {{0,10},{1,20}}},
  };

  for (auto& [n, l] : tests)
  {
    std::cout <<  "---\nn: " << n << ", logs: ";
    printM(l);
    std::cout <<  "\nhardestWorker: ";
    std::cout << Solution().hardestWorker(n, l) << std::endl;
  }
  return 0;
}
