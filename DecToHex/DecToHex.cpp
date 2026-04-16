// DecToHex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    char chAnswer;
    long long uDecNum, uTempVal;
    std::string strHexNum;
    std::cout << "Input an unsigned integer number\r\n";
    std::cin >> uDecNum;
    if (uDecNum < 0 or uDecNum > UINT32_MAX)
    {
        std::cout << "Incorrect number format\r\n";
        std::cin.ignore();
        std::cin.get();
        return 0;
    }
    std::cout << "Lower case ? (y / n) ";
    std::cin >> chAnswer;
    bool bLowerCase = (chAnswer == 'y' || chAnswer == 'Y');
    uTempVal = uDecNum;
    while (uTempVal > 0)
    {
        long long nHexDigit = uTempVal % 16;
        char chHexDigit = '\0';
        if (nHexDigit >= 0 && nHexDigit <= 9)
            chHexDigit = static_cast<char>(nHexDigit + '0');
        else if (nHexDigit >= 10 && nHexDigit <= 15 && bLowerCase)
            chHexDigit = static_cast<char>(nHexDigit - 10 + 'a');
        else if (nHexDigit >= 10 && nHexDigit <= 15)
            chHexDigit = static_cast<char>(nHexDigit - 10 + 'A');
        strHexNum = chHexDigit + strHexNum;
        uTempVal /= 16;
    }
    if (strHexNum.empty()) strHexNum = "0";
    std::cout << "The hexadecimal equivalent of the decimal number " 
              << uDecNum << " is:" << strHexNum << "\r\n";
    std::cin.ignore();
    std::cin.get();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
