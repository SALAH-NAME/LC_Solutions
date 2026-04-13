#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool squareIsWhite(std::string coordinates)
		{
        int col = coordinates[0] - 'a' + 1;
        int row = coordinates[1] - '0';

        return (row + col) % 2 == 1;
    }
};

typedef struct testCase
{
    std::string coordinates;
} testCase;

int main()
{
    std::vector<testCase> tests = {
        {"a1"},
        {"h3"},
        {"c7"},
        {"d4"},
        {"e8"}
    };

    for (auto& [coordinates] : tests)
		{
        std::cout << "---\ncoordinates: '" << coordinates << "'\n";
        std::cout << "squareIsWhite: ";
        std::cout << (Solution().squareIsWhite(coordinates) ? "true" : "false") << std::endl;
    }

    return 0;
}

