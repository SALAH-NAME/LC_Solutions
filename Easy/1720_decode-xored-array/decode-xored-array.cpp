#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> decode(std::vector<int>& encoded, int first)
  {
    std::vector<int> arr;
    arr.push_back(first);
    for (int i = 0; i < encoded.size(); i++)
      arr.push_back(arr[i] ^ encoded[i]);
    return arr;
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
  std::vector<int> e;
  int f;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,2,3}, 1},
    {{6,2,7,3}, 4},
  };

  for (auto& [e, f] : tests)
  {
    std::cout << "---\nencoded: ";
    printV(e);
    std::cout << ", first: " << f << "\ndecoded: ";
    printV(Solution().decode(e, f));
    std::cout << std::endl;
  }
  return 0;
}
