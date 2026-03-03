#include <iostream>

class ParkingSystem
{
private:
	int bigSlots;
	int mediumSlots;
	int smallSlots;

public:
	ParkingSystem(int big, int medium, int small) : bigSlots(big), mediumSlots(medium), smallSlots(small) {}

	bool addCar(int carType)
	{
		if (carType == 1)
		{
			if (bigSlots > 0)
			{
				bigSlots--;
				return true;
			}
		}
		else if (carType == 2)
		{
			if (mediumSlots > 0)
			{
				mediumSlots--;
				return true;
			}
		}
		else if (carType == 3)
		{
			if (smallSlots > 0)
			{
				smallSlots--;
				return true;
			}
		}
		return false;
	}
};


int main() {
	ParkingSystem* obj = new ParkingSystem(1, 1, 0);
	std::cout << obj->addCar(1) << std::endl; // true
	std::cout << obj->addCar(2) << std::endl; // true
	std::cout << obj->addCar(3) << std::endl; // false
	std::cout << obj->addCar(1) << std::endl; // false
	return 0;
}
