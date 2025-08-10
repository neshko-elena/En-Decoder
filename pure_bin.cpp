#include "pure_bin.h"
#include <string>
#include <bitset>
#include <vector>

std::string pure_bin(const std::string& input)
{
	std::string result;
	for (char c : input)
	{
		unsigned char uncp = static_cast<unsigned char>(c);
		std::bitset<8> bits(uncp);
		result += bits.to_string() + " ";
	}
	return result;
}