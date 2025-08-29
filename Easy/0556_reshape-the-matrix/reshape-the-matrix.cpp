#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c)
	{
		unsigned char rowSize = mat.size();
		unsigned char colSize = mat[0].size();

		if (rowSize * colSize != r * c) return mat;
		
		std::vector<std::vector<int>> res(r, std::vector<int>(c));
		short posRO = 0, posCO = 0;

		for (short posRR = 0; posRR < r; ++posRR)
		{
			for (short posCR = 0; posCR < c; ++posCR)
			{
				res[posRR][posCR] = mat[posRO][posCO];
				++posCO;
				if (posCO == colSize)
				{
					posCO = 0;
					posRO++;
				}
			}
		}
		return res;
	}
};
