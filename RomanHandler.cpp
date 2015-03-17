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

std::string RomanHandler::returnval(float input) {
    std::string returnstr;
    int val, mcount = 0, ccount = 0, icount = 0, xcount = 0;

    val = input;
    while (val != 0) {
        if ((val - 1000)>=0) {
            val = val-1000;
            mcount++;
        }
        else {
            if ((val - 100) >= 0) {
                val = val-100;
                ccount++;
            }
            else {
                if ((val - 10) >= 0) {
                    val = val-10;
                    xcount++;
                }
                else {
                    val = val-1;
                    icount++;
                }
            }
        }
    }
    for (int i=1; i<=mcount; i++) {
            returnstr = returnstr + 'M';
        }


    if (ccount == 9) {
        returnstr = returnstr + "CM";
        ccount = ccount - 9;
    }
    else if (ccount >= 5) {
        returnstr = returnstr + "D";
        ccount = ccount - 5;
    }
    else if (ccount == 4) {
        returnstr = returnstr + "CD";
        ccount = ccount - 4;
    }
    for (int i=1; i<=ccount; i++) {
        returnstr = returnstr + 'C';
    }


    if (xcount == 9) {
        returnstr = returnstr + "XC";
        xcount = xcount - 9;
    }
    else if (xcount >= 5) {
        returnstr = returnstr + "L";
        xcount = xcount - 5;
    }
    else if (xcount == 4) {
        returnstr = returnstr + "XL";
        xcount = xcount - 4;
    }
    for (int i=1; i<=xcount; i++) {
        returnstr = returnstr + 'X';
    }


    if (icount == 9) {
        returnstr = returnstr + "IX";
        icount = icount - 9;
    }
    else if (icount >= 5) {
        returnstr = returnstr + "V";
        icount = icount - 5;
    }
    else if (icount == 4) {
        returnstr = returnstr + "IV";
        icount = icount - 4;
    }
    for (int i=1; i<=icount; i++) {
        returnstr = returnstr + 'I';
    }

    return returnstr;
}
