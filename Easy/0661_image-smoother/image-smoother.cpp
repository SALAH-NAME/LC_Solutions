#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img)
	{
		int sizeY = img.size(), sizeX = img[0].size();
		std::vector<std::vector<int>> result(sizeY, std::vector<int>(sizeX));

		for (int y = 0; y < sizeY; ++y)
		{
			for (int x = 0; x < sizeX; ++x)
			{
				int sum = 0, count = 0;

				for (int dy = -1; dy <= 1; ++dy)
				{
					for (int dx = -1; dx <= 1; ++dx)
					{
						int ny = y + dy, nx = x + dx;
						if (ny >= 0 && ny < sizeY && nx >= 0 && nx < sizeX)
						{
							sum += img[ny][nx];
							count++;
						}
					}
				}
				result[y][x] = sum / count;
			}
		}
		return result;
	}
};
