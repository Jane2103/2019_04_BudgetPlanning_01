#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertFloatToStr(float numberToConvert) {
    stringstream floatToStr;
    string str;
    floatToStr << numberToConvert;
    floatToStr >> str;
    floatToStr.clear();
    return str;
}

string AuxiliaryMethods::intToStr(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
