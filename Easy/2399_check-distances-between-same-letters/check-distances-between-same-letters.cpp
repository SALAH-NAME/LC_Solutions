#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool checkDistances(std::string s, std::vector<int>& distance)
  {
    std::vector<int> first_seen(26, -1);

    for (int i = 0; i < s.length(); i++)
    {
      int j = s[i] - 'a';

      if (first_seen[j] != -1)
      {
        int current_distance = i - first_seen[j] - 1;
        if (current_distance != distance[j])
        {
          return false;
        }
      }
      else
      {
        first_seen[j] = i;
      }
    }
    return true;
  }
};

typedef struct testCase
{
  std::string s;
  std::vector<int> d;
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
    {"abaccb", {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {"aa", {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
  };

  for (auto& [s, d] : tests)
  {
    std::cout << "---\ns: '" << s << "'\ndistance: ";
    printV(d);
    std::cout << "\ncheckDistances: ";
    std::cout << (Solution().checkDistances(s, d) ? "True" : "False") << std::endl;
  }
  return 0;
}
