#include <string>
#include "Binary.h"
#include <iostream>
#include <bitset>
#include <vector>

std::string Binary(const std::string& input)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	std::cout << "Please choose an option:\n1) Decode\n2) Encode\n";
	int optB;
	std::cin >> optB;
	std::string result;
	if (optB == 2) //text to binary
	{
		for (char c : input)
		{
			unsigned char unc = static_cast<unsigned char>(c);
			std::bitset<8> bits(unc);
			result += bits.to_string() + " ";
		}
	}
	else //binary to text
	{
		std::string bytesCon;
		int bitCount = 0;
		for (char c : input)
		{
			if (c != '0' && c != '1' && c != ' ')
			{
				std::cerr << "Error!\nInvalid character in the binary string: " << c << std::endl;
				return "";
			}
			else if (c == ' ')
			{
				if (!bytesCon.empty())
				{
					std::bitset<8> bits(bytesCon);
					result += static_cast<char>(bits.to_ulong());
					bytesCon.clear();
					bitCount = 0;
				}
			}
			else
			{
				bytesCon += c;
				bitCount++;
				if (bitCount == 8)
				{
					std::bitset<8> bits(bytesCon);
					result += static_cast<char>(bits.to_ulong());
					bytesCon.clear();
					bitCount = 0;
				}
			}
		}
	}
	return result;
}