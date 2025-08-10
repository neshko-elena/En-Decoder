#include "pure_bin.h"
#include <bitset>
#include <iostream>
#include <vector>

std::vector<long long> pure_bin(const std::string& input)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	std::vector<long long> result;
	for (char c : input)
	{
		unsigned char uncp = static_cast<unsigned char>(c);
		std::bitset<8> bits(uncp);
		for (int i = 7; i >= 0; --i)
		{
			result.push_back(bits[i] ? 1 : 0);
		}
	}
	return result;
}