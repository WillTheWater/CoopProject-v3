#pragma once
#include <random>

namespace Random
{
	extern std::random_device rd;
	extern std::seed_seq ss;
	extern std::mt19937 mt;
	int getRandomIndex(int min, int max);

	int getRandomInt(int min, int max);

	double getRandomDouble(int min, int max);
};