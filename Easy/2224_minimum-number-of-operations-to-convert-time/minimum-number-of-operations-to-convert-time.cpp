#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int convertTime(std::string current, std::string correct)
  {
    int current_mins = std::stoi(current.substr(0,2)) * 60 + std::stoi(current.substr(3,2));
    int correct_mins = std::stoi(correct.substr(0,2)) * 60 + std::stoi(correct.substr(3,2));
    
    int diff = correct_mins - current_mins;
    int operations = 0;

    operations += diff / 60;
    diff %= 60;

    operations += diff / 15;
    diff %= 15;

    operations += diff / 5;
    diff %= 5;

    operations += diff;

    return operations;
  }
};

typedef struct testCase
{
  std::string cu;
  std::string co;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"02:30", "04:35"},
    {"11:00", "11:01"},
  };

  for (auto& [cu, co] : tests)
  {
    std::cout << "---\ncurrent: '" << cu << "', correct: '" << co << "'\n";
    std::cout << "convertTime: ";
    std::cout << Solution().convertTime(cu, co) << std::endl;
  }
  return 0;
}
