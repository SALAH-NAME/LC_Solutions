#include <numeric>
#include <vector>
#include <iostream>

class Solution
{
public:
  int minNumberOfHours(int initialEnergy, int initialExperience, std::vector<int>& energy, std::vector<int>& experience)
  {
    int trainingHours = 0;
    int totalEnergyNeeded = 0;
    for (int e : energy)
    {
      totalEnergyNeeded += e;
    }
    if (initialEnergy <= totalEnergyNeeded)
    {
      trainingHours += (totalEnergyNeeded - initialEnergy + 1);
    }

    for (int exp : experience)
    {
      if (initialExperience <= exp)
      {
        int needed = exp - initialExperience + 1;
        trainingHours += needed;
        initialExperience += needed;
      }
      initialExperience += exp;
    }
    return trainingHours;
  }
};

typedef struct testCase
{
  int initialEnergy;
  int initialExperience;
  std::vector<int> energy;
  std::vector<int> experience;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {5, 3, {1, 4, 3, 2}, {2, 6, 3, 1}},
    {2, 4, {1}, {3}},
  };

  for (auto& [initEn, initEx, en, ex] : tests)
  {
    std::cout << "---\ninitialEnergy: " << initEn << ", initialExperience: ";
    std::cout << initEx << "\nminNumberOfHours: ";
    std::cout << Solution().minNumberOfHours(initEn, initEx, en, ex) << std::endl;
  }
  return 0;
}
