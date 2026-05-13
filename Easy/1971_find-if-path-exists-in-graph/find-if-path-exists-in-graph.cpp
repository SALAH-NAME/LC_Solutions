#include <queue>
#include <vector>
#include <iostream>

class Solution
{
public:
  bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination)
  {
    if (source == destination) return true;

    std::vector<std::vector<int>> adj(n);
    for (const auto& edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> visited(n, false);
    std::queue<int> q;

    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();

      if (curr == destination) return true;

      for (int neighbor : adj[curr])
      {
        if (!visited[neighbor])
        {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    return false;
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

void printMat(const std::vector<std::vector<int>>& m)
{
  std::cout << "{";
  for (int i = 0; i < m.size(); i++)
  {
    printV(m[i]);
    if (i < m.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  int n;
  std::vector<std::vector<int>> e;
  int s;
  int d;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {3, {{0,1},{1,2},{2,0}}, 0, 2},
    {6, {{0,1},{0,2},{3,5},{5,4},{4,3}}, 0, 5},
  };

  for (auto& [n, e, s, d] : tests)
  {
    std::cout << "---\nn: " << n << ",edges: ";
    printMat(e);
    std::cout << "\nsource: " << s << ", destination: " << d;
    std::cout << "\nvalidPath: ";
    std::cout << (Solution().validPath(n, e, s, d) ? "True" : "False");
    std::cout << std::endl;
  }
  return 0;
}
