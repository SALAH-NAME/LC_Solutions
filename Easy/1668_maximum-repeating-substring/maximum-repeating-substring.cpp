#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    int maxRepeating(std::string sequence, std::string word)
    {
        int maxCount = 0;
        int n = sequence.size();
        int m = word.size();

        for (int i = 0; i <= n - m; i++)
        {
            int count = 0;
            while (sequence.substr(i + count * m, m) == word)
            {
                count++;
            }
            maxCount = std::max(maxCount, count);
        }
        return maxCount;
    }
};

typedef struct testCase
{
    std::string sequence;
    std::string word;
} testCase;

int main()
{
    std::vector<testCase> tests = {
        {"ababc", "ab"},
        {"ababc", "ba"},
        {"ababc", "ac"},
        {"aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba"},
    };

    for (auto& [sequence, word] : tests)
    {
        std::cout << "---\nsequence: " << sequence;
        std::cout << ", word: " << word;
        std::cout << "\nmaxRepeating: ";
        std::cout << Solution().maxRepeating(sequence, word);
        std::cout << std::endl;
    }
    return 0;
}
