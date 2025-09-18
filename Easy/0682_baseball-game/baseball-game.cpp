#include <cstdlib>
#include <vector>
#include <string>

class Solution
{
public:
	int calPoints(std::vector<std::string>& operations)
	{
		std::vector<int> record;
		record.reserve(operations.size());
		int sum = 0;

		for (auto &op : operations)
		{
			if (op == "C")
			{
				sum -= record.back();
				record.pop_back();
			}
			else if (op == "D")
			{
				record.push_back(record.back() * 2);
				sum += record.back();
			}
			else if (op == "+")
			{
				record.push_back(record.back() + record[record.size() - 2]);
				sum += record.back();
			}
			else
			{
				record.push_back(std::stoi(op));
				sum += record.back();
			}
		}
		record.clear();
		return sum;
	}
};
