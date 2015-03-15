#include <iostream>
#include <string>
#include <stdlib.h>
#include "LogicHandler.h"

LogicHandler::LogicHandler() : value(0) {
}

LogicHandler::LogicHandler(const LogicHandler& AH) : value(AH.value) {
}

LogicHandler::~LogicHandler(){
}

LogicHandler& LogicHandler::operator=(const LogicHandler& AH){
    value = AH.value;
    return *this;
}

void LogicHandler::setvalue(std::string value) {
    try {
        if (value.compare("true") != 0 && value.compare("false") != 0 && value.compare("1") != 0 && value.compare("0") != 0) {
            throw -1;
        }
        int x = 0;
        float f = 0;

        if (value.compare("0") == 0 ||value.compare("1") == 0) {
            f = atof(&value[x]);
            this->value = f;
        }
        else {
            if (value.compare("true") == 0) {
                this->value = 1;
            }
            else {
                if (value.compare("false") == 0) {
                    this->value = 0;
                }
            }
        }
    }
    catch (int) {
        std::cerr << "Wrong Input" << std::endl;
    }
}

float LogicHandler::getvalue() const {
	return value;
}
