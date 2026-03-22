#include <queue>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countStudents(std::vector<int>& students, std::vector<int>& sandwiches)
  {
    std::queue<int> q;
    for (int s : students) q.push(s);

    int idx = 0;
    int rotations = 0;

    while (!q.empty() && rotations < q.size())
    {
      if (q.front() == sandwiches[idx])
      {
        q.pop();
        idx++;
        rotations = 0;
      }
      else
      {
        q.push(q.front());
        q.pop();
        rotations++;
      }
    }

    return q.size();
  }
};

typedef struct testCase
{
  std::vector<int> st;
  std::vector<int> sa;
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
    {{1,1,0,0}, {0,1,0,1}},
    {{1,1,1,0,0,1}, {1,0,0,0,1,1}},
  };

  for (auto& [st, sa] : tests)
  {
    std::cout << "---\nstudents: ";
    printV(st);
    std::cout << ", sandwiches: ";
    printV(sa);
    std::cout << "\ncountStudents: ";
    std::cout << Solution().countStudents(st, sa) << std::endl;
  }
  return 0;
}
