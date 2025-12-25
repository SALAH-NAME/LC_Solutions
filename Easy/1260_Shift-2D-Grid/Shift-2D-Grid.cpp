#include <vector>
#include <algorithm>

class Solution
{
public:
 std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k)
 {
     int m = grid.size();
     int n = grid[0].size();
     int total = m * n;

     std::vector<int> flat;
     flat.reserve(total);
     for (const auto& row : grid)
       flat.insert(flat.end(), row.begin(), row.end());
      
     k %= total;
     std::rotate(flat.begin(), flat.end() - k, flat.end());
     std::vector<std::vector<int>> result(m, std::vector<int>(n));
     for (int i = 0; i < total; ++i) 
       result[i / n][i % n] = flat[i];

     return result;
  }
};
