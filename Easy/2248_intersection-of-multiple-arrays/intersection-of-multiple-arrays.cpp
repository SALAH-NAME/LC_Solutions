#include <map>
#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> intersection(std::vector<std::vector<int>>& nums)
  {
    std::map<int, int> counts;

    for (const auto& row : nums)
    {
      for (int num : row)
      {
        counts[num]++;
      }
    }

    std::vector<int> result;
    int target_count = nums.size();

    for (const auto& [num, count] : counts)
    {
      if (count == target_count)
      {
        result.push_back(num);
      }
    }
    return result;
  }
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); ++i)
	{
		printV(m[i]);
		if (i < m.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> nums;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{{3,1,2,4,5},{1,2,3,4},{3,4,5,6}}},
    {{{1,2,3},{4,5,6}}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printMat(n);
    std::cout << "\nintersection: ";
    printV(Solution().intersection(n));
    std::cout <<std::endl;
  }
  return 0;
}
