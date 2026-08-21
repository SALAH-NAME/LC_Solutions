#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<double> convertTemperature(double celsius)
  {
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius * 1.80 + 32.00;
    return {kelvin, fahrenheit};
  }
};

void printV(const std::vector<double>& v)
{
  std::cout << "{";
  for(int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  double c;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{36.50}},
    {{122.11}},
  };

  for (auto& [c] : tests)
  {
    std::cout << "---\ncelsius: " << c << "\nconvertTemperature: ";
    printV(Solution().convertTemperature(c));
    std::cout << std::endl;
  }
  return 0;
}
