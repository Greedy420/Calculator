#include <iostream>
#include <string>
#include <stdlib.h>
#include "AngkaHandler.h"

AngkaHandler::AngkaHandler() : value(0) {
}

AngkaHandler::AngkaHandler(const AngkaHandler& AH) : value(AH.value) {
}

AngkaHandler::~AngkaHandler(){
}

AngkaHandler& AngkaHandler::operator=(const AngkaHandler& AH){
    value = AH.value;
    return *this;
}

void AngkaHandler::setvalue(std::string value) {
    try {
    	int once = 0;
        int x = 0;
        float f = 0;
        while (value[x] != '\0') {
            char test = value[x];
            if (test != '0' && test != '1' && test != '2' && test != '3' && test != '4' && test != '5' && test != '6' && test != '7' && test != '8' && test != '9' && test != '.') {
                throw -1;
            }
            if (test == '.' && once == 1)
            	throw -1; 
            else if (test == '.' && once == 0) 
            	once = 1;
            x++;
        }
        x = 0;
        f = atof(&value[x]);
        this->value = f;
    }
    catch(int) {
        this->value = 0;
        std::cerr << "Wrong Input" << std::endl;
    }
}

float AngkaHandler::getvalue() const {
	return value;
}
