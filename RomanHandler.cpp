#include <iostream>
#include <string>
#include "RomanHandler.h"

RomanHandler::RomanHandler() : value(0) {
}

RomanHandler::RomanHandler(const RomanHandler& RH) : value(RH.value) {
}

RomanHandler::~RomanHandler(){
}

RomanHandler& RomanHandler::operator=(const RomanHandler& RH){
    value = RH.value;
    return *this;
}

void RomanHandler::setvalue(std::string value) {
	try {
        float decimal = 0;
        int x = 0;

        std::string romanNumeral = value;
        while(value[x] != '\0')
        {
            char convertToDecimal = value[x];

            switch (convertToDecimal)
            {
            case 'M':
                decimal += 1000;
                break;

            case 'D':
                decimal += 500;
                break;

            case 'C':
                decimal += 100;
                break;

            case 'L':
                decimal += 50;
                break;

            case 'X':
                decimal += 10;
                break;

            case 'V':
                decimal += 5;
                break;

            case 'I':
                decimal += 1;
                break;

            default :
                throw -1;
            }
            x++;
        }
        if (romanNumeral.find("IV") != std::string::npos)
        {
            decimal-=2;
        }
        if (romanNumeral.find("IX") != std::string::npos)
        {
            decimal-=2;
        }
        if (romanNumeral.find("XL") != std::string::npos)
        {
            decimal-=20;
        }
        if (romanNumeral.find("XC") != std::string::npos)
        {
            decimal-=20;
        }
        if (romanNumeral.find("CD") != std::string::npos)
        {
            decimal-=200;
        }
        if (romanNumeral.find("CM") != std::string::npos)
        {
            decimal-=200;
        }
        this->value = decimal;
	}
	catch(int) {
	    this->value = 0;
        std::cerr << "Wrong Input" << std::endl;
	}
}

float RomanHandler::getvalue() const {
	return value;
}
