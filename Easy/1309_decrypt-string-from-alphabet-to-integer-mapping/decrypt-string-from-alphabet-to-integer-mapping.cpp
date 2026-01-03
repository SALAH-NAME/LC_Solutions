#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Solution
{
public:
  std::string freqAlphabets(const std::string& s)
  {
    std::string res;
    int i = static_cast<int>(s.size()) - 1;
    
    while (i >= 0)
    {
      if (s[i] == '#')
      {
        int num = std::stoi(s.substr(i - 2, 2));
        res.push_back(static_cast<char>(96 + num));
        i -= 3;
      }
      else
      {
        int num = s[i] - '0';
        res.push_back(static_cast<char>(96 + num));
        i--;
      }
    }
    
    std::reverse(res.begin(), res.end());
    return res;
  }
};

int main()
{
  std::vector<std::string> tests = {"10#11#12", "1326#"};
  
  for (const auto& s : tests)
  {
    std::cout << "---Input: '" << s << "'\n"
              << "Output: " << Solution ().freqAlphabets(s) 
              << "\n";
  }
  return 0;
}
