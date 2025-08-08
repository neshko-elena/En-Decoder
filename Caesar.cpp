#include "Caesar.h"
#include <string>
#include <iostream>
#include <algorithm> 
#include <cctype>
#include <windows.h>

std::string ConvertToCaesar(const std::string& input)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::string r_alph = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
	std::string R_alph = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
	std::string e_alph = "abcdefghijklmnopqrstuvwxyz";
	std::string E_alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::cout << "Please choose an option:\n1) Decode\n2) Encode\n";
	int opt;
	std::cin >> opt;
	std::string result;
	long long key;
	std::cout << "Please insert the key:\n";
	std::cin >> key;
	std::string final;
	int np;
	if(opt==1)
	for (char c : input)
	{
		bool r_al = false;
		bool R_al = false;
		bool e_al = false;
		bool E_al = false;
		long long s = 0;
		for (int i=0; i <= 32; i++)
		{
			if (c == r_alph[i])
			{
				r_al = true;
				np = i;
				break;
			}
			else if (c == R_alph[i])
			{
				R_al = true;
				np = i;
				break;
			}
		}
		for (int i = 0; i <= 25; i++)
		{
			if (c == e_alph[i])
			{
				e_al = true;
				np = i;
				break;
			}
			else if (c == E_alph[i])
			{
				E_al = true;
				np = i;
				break;
			}
		}
		if (r_al)
		{
			s = (np - key) % 33;
			if (s < 0)
				s += 33;
			final += r_alph[s];
		}
		else if (R_al)
		{
			s = (np - key) % 33;
			if (s < 0)
				s += 33;
			final += R_alph[s];
		}
		else if (e_al)
		{
			s = (np - key) % 26;
			if (s < 0)
				s += 26;
			final += e_alph[s];
		}
		else if (E_al)
		{
			s = (np - key) % 26;
			if (s < 0)
				s += 26;
			final += E_alph[s];
		}
		else
			final += c;
	}
	else
		for (char c : input)
		{
			bool r_al = false;
			bool R_al = false;
			bool e_al = false;
			bool E_al = false;
			long long s = 0;
			for (int i = 0; i <= 32; i++)
			{
				if (c == r_alph[i])
				{
					r_al = true;
					np = i;
					break;
				}
				else if (c == R_alph[i])
				{
					R_al = true;
					np = i;
					break;
				}
			}
			for (int i = 0; i <= 25; i++)
			{
				if (c == e_alph[i])
				{
					e_al = true;
					np = i;
					break;
				}
				else if (c == E_alph[i])
				{
					E_al = true;
					np = i;
					break;
				}
			}
			if (r_al)
			{
				s = (np + key) % 33;
				if (s < 0)
					s += 33;
				final += r_alph[s];
			}
			else if (R_al)
			{
				s = (np + key) % 33;
				if (s < 0)
					s += 33;
				final += R_alph[s];
			}
			else if (e_al)
			{
				s = (np + key) % 26;
				if (s < 0)
					s += 26;
				final += e_alph[s];
			}
			else if (E_al)
			{
				s = (np + key) % 26;
				if (s < 0)
					s += 26;
				final += E_alph[s];
			}
			else
				final += c;
		}
	return final;
}