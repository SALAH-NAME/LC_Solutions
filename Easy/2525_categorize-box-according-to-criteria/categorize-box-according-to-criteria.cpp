#include <vector>
#include <iostream>

class Solution
{
public:
  std::string categorizeBox(int length, int width, int height, int mass)
  {
    long long volume = static_cast<long long>(length) * width * height;
        
    bool isBulky = (length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000LL);
    bool isHeavy = (mass >= 100);
        
    if (isBulky && isHeavy) return "Both";
    if (!isBulky && !isHeavy) return "Neither";
    if (isBulky) return "Bulky";
    return "Heavy";
  }
};

typedef struct testCase
{
  int l;
  int w;
  int h;
  int m;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {1000, 35, 700, 300},
    {200, 50, 800, 50},
  };

  for (auto& [l, w, h, m] : tests)
  {
    std::cout << "---\nlength: " << l << ", width: " << w << ", height: " << h;
    std::cout << ", mass: " << m << "\ncategorizeBox: ";
    std::cout << "'" << Solution().categorizeBox(l, w, h, m) << "'" << std::endl;
  }
  return 0;
}
