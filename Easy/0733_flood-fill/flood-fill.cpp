#include <vector>

class Solution
{
private:
	void dfs(std::vector<std::vector<int>>& image, int r, int c, int originalColor, int newColor)
	{
		if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size()) return;

		if (image[r][c] != originalColor) return;

		image[r][c] = newColor;

		dfs(image, r - 1, c, originalColor, newColor);
		dfs(image, r + 1, c, originalColor, newColor);
		dfs(image, r, c - 1, originalColor, newColor);
		dfs(image, r, c + 1, originalColor, newColor);
	}
public:
	std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
	{
		int originalColor = image[sr][sc];
		if (originalColor == color) return image;
		dfs(image, sr, sc, originalColor, color);
		return image;
	}
};
