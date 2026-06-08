#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  int countPoints(std::string rings)
  {
    int rods[10] = {0};
    for (int i = 0; i < rings.size() - 1; i += 2)
    {
      switch (rings[i]) {
        case 'R':
          rods[rings[i+1] - '0'] |= 1;
          break;
        case 'G':
          rods[rings[i+1] - '0'] |= 2;
          break;
        case 'B':
          rods[rings[i+1] - '0'] |= 4;
          break;
      }
    }
    int count = 0;
    for (int i = 0; i < 10; i++)
      if (rods[i] == 7)
        count++;
    return count; 
  }
};

typedef struct testCase
{
  std::string r;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"B0B6G0R6R0R6G9"},
    {"B0R0G0R9R0B0G0"},
    {"G4"},
  };

  for (auto& [r] : tests)
  {
    std::cout << "---\nrings: '" << r << "'\ncountPoints: ";
    std::cout << Solution().countPoints(r) << std::endl;
  }
  return 0;
}
