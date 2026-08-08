#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob)
  {
    std::vector<int> daysInMonths = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto convertToDayNumber = [&](const std::string& dateStr) -> int {
      int month = std::stoi(dateStr.substr(0, 2));
      int day = std::stoi(dateStr.substr(3, 2));

      int totalDays = 0;
      for (int i = 0; i < month; ++i)
      {
        totalDays += daysInMonths[i];
      }
      totalDays += day;
      return totalDays;
    };
    int arriveA = convertToDayNumber(arriveAlice);
    int leaveA = convertToDayNumber(leaveAlice);
    int arriveB = convertToDayNumber(arriveBob);
    int leaveB = convertToDayNumber(leaveBob);
    int overlapStart = std::max(arriveA, arriveB);
    int overlapEnd = std::min(leaveA, leaveB);
    int overlappingDays = overlapEnd - overlapStart + 1;
    return std::max(overlappingDays, 0);
  }
};

typedef struct testCase
{
  std::string aa;
  std::string la;
  std::string ab;
  std::string lb;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {"08-15", "08-18", "08-16", "08-19"},
    {"10-01", "10-31", "11-01", "12-31"},
  };

  for (auto& [aa, la, ab, lb] : tests)
  {
    std::cout << "---\narriveAlice: " << aa << ", leaveAlice: " << la;
    std::cout << "\narriveBob: " << ab << ", leaveBob: " << lb;
    std::cout << "\ncountDaysTogether: ";
    std::cout << Solution().countDaysTogether(aa, la, ab, lb) << std::endl;
  }
  return 0;
}
