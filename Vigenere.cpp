#include <iostream>
#include <string>
#include <vector>
#include "Vigenere.h"

std::string ConvertToVig(const std::string& input)
{
	std::string r_alph = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
	std::string R_alph = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
	std::string e_alph = "abcdefghijklmnopqrstuvwxyz";
	std::string E_alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::cout << "Please insert the key:\n";
	std::string keyV;
	std::cin >> keyV; 
	std::string resultV;
	int key_c = 0;
	std::cout << "Please choose an option:\n1) Decode\n2) Encode\n";
	int optV;
	std::cin >> optV;
	if(optV == 2)
	{
		for (char c : input)
		{
			bool r_al = false;
			bool R_al = false;
			bool e_al = false;
			bool E_al = false;
			int np = -1;

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
				char kc = keyV[key_c % keyV.size()];
				key_c++;
				int kp = -1;
				kp = r_alph.find(kc);
				if (kp == -1)
				{
					kp = R_alph.find(kc);
				}
				int es = (np + kp) % 33;
				resultV += r_alph[es];

			}
			else if (R_al)
			{
				char kc = keyV[key_c % keyV.size()];
				key_c++;
				int kp = -1;
				kp = R_alph.find(kc);
				if (kp == -1)
				{
					kp = r_alph.find(kc);
				}
				int es = (np + kp) % 33;
				resultV += R_alph[es];

			}
			else if (e_al)
			{
				char kc = keyV[key_c % keyV.size()];
				key_c++;
				int kp = -1;
				kp = e_alph.find(kc);
				if (kp == -1)
				{
					kp = E_alph.find(kc);
				}
				int es = (np + kp) % 26;
				resultV += e_alph[es];

			}
			else if (E_al)
			{
				char kc = keyV[key_c % keyV.size()];
				key_c++;
				int kp = -1;
				kp = E_alph.find(kc);
				if (kp == -1)
				{
					kp = e_alph.find(kc);
				}
				int es = (np + kp) % 26;
				resultV += E_alph[es];

			}
			else
				resultV += c;

		}
		return resultV;
	}
	else if (optV == 1)
		{
			for (char c : input)
			{
				bool r_al = false;
				bool R_al = false;
				bool e_al = false;
				bool E_al = false;
				int np = -1;

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
					char kc = keyV[key_c % keyV.size()];
					key_c++;
					int kp = -1;
					kp = r_alph.find(kc);
					if (kp == -1)
					{
						kp = R_alph.find(kc);
					}
					int es = (np - kp+33) % 33;
					resultV += r_alph[es];

				}
				else if (R_al)
				{
					char kc = keyV[key_c % keyV.size()];
					key_c++;
					int kp = -1;
					kp = R_alph.find(kc);
					if (kp == -1)
					{
						kp = r_alph.find(kc);
					}
					int es = (np - kp+33) % 33;
					resultV += R_alph[es];

				}
				else if (e_al)
				{
					char kc = keyV[key_c % keyV.size()];
					key_c++;
					int kp = -1;
					kp = e_alph.find(kc);
					if (kp == -1)
					{
						kp = E_alph.find(kc);
					}
					int es = (np - kp+26) % 26;
					resultV += e_alph[es];

				}
				else if (E_al)
				{
					char kc = keyV[key_c % keyV.size()];
					key_c++;
					int kp = -1;
					kp = E_alph.find(kc);
					if (kp == -1)
					{
						kp = e_alph.find(kc);
					}
					int es = (np - kp+26) % 26;
					resultV += E_alph[es];

				}
				else
					resultV += c;

			}
			return resultV;
			}
}

