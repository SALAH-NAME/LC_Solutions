#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
  std::vector<std::string> divideString(std::string s, int k, char fill)
  {
    int n = s.size();
    if (!n) return {};

    int size = (n + k - 1) / k;
    std::vector<std::string> res;
    res.reserve(size);

    for (int pos = 0; pos < n; pos += k)
    {
      res.push_back(s.substr(pos, k));
    }

    int r = n % k;
    if (r)
    {
      res.back().append(k - r, fill);
    }

    return res;
  }
};

void printV(const std::vector<std::string>& v)
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
  std::string s;
  int k;
  char f;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"abcdefghi", 3, 'x'},
    {"abcdefghij", 3, 'x'},
  };

  for (auto& [s, k, f] : tests)
  {
    std::cout << "---\ns: '" << s << "', k: " << k << ", fill: '" << f << "'\n";
    std::cout << "divideString: ";
    printV(Solution().divideString(s, k, f));
    std::cout << std::endl;
  }
  return 0;
}
