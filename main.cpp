#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>
#include <limits>
#include <map>
#include "keyboard_map.h"
#include <windows.h>
#include "Caesar.h"
#include "Vigenere.h"
#include "Morse.h"
#include "Atbash.h"
#include "Binary.h"
/*
1) просто перевод англ клавы в рус и наоборот +
2) шифр Цезаря +
3) шифр Виженера +
4) пигпен -
5) морзе +
6) добавить пароль на админскую панель (по сути всю инфу из этого коммента в нее перенести) -
7) зашифровать пароль (можно по принципу шифра Варнама) -
8) атбаш +
9) Плейфер??
10) бинарный
11) Вернам
12) тг бот!!
*/
int main()
{
    std::string text;
    std::string answ;
    bool y = 0;
    while (!y)
    {
        std::cout << "Insert the text: ";
        std::getline(std::cin, text);
        std::cout << "Your text: " << text << std::endl << "Is the text correct?" << std::endl;
        std::cout << "Y/N" << std::endl;
        std::cin >> answ;
        std::transform(answ.begin(), answ.end(), answ.begin(), ::tolower);
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        if (y == 0)
        {
            if (answ == "y" || answ == "yes")
            {
                y = true;
            }
            else if (answ == "n" || answ == "no")
            {
                std::cout << "Please proceed to insert the correct text: " << std::endl;
            }
            else
                std::cout << "Please try again" << std::endl;
        }
    }
    std::cout << "Confirmed the text: " << text << std::endl;
    std::cout << "Please choose an option: " << std::endl << "1) Keyboard layout\n" << "2) Caesar cipher\n" << "3) Vigenere cipher\n4) Morse code\n5) Atbash cipher\n6) Binary\n";
    int optC;
    std::cin >> optC;
    switch (optC)
    {
    case 1:
        std::cout << ConvertToKL(text);
        break;
    case 2:
        std::cout << ConvertToCaesar(text);
        break;
    case 3:
        std::cout << ConvertToVig(text);
        break;
    case 4:
        std::cout << "Attention: this function performs encoding only!\nDo you wish to proceed?\nYes(Y)/No(N)\n";
        std::cin >> answ;
        if (answ == "y" || answ == "Y")
        {
            std::cout << Morse(text);
            break;
        }
        else
            break;
    case 5:
        std::cout << Atbash(text);
        break;
    case 6:
        std::cout << Binary(text);
        break;
    }
    return 0;
}