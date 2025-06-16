#include <cstdint>
#include <iostream>
#include <bitset>

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t rev = 0;
		
		for (int i = 0 ; i < 32; ++i)
		{
			rev = rev << 1;
			rev |= ((n >> i) & 1);
		}
		return rev;
	}
};


int main()
{
	int number = 43261596;
	std::bitset<32> binary(number);
	std::cout << "BIN: " << binary << std::endl;
	
	std::cout << std::endl;

	int rev = Solution().reverseBits(number);
	std::bitset<32> binaryRev(rev);
	std::cout << "BIN: " << binaryRev << std::endl;
	return 0;
}
