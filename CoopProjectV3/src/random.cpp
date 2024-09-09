#include "random.h"

namespace Random
{
	std::random_device rd{};
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ ss };
	int getRandomIndex(int min, int max)
	{
		return static_cast<std::size_t>(std::uniform_int_distribution{ min, max }(mt));
	}
	int getRandomInt(int min, int max)
	{
		return std::uniform_int_distribution{ min, max }(mt);
	}
	double getRandomDouble(int min, int max)
	{
		return static_cast<double>(std::uniform_int_distribution{ min, max }(mt));
	}
};