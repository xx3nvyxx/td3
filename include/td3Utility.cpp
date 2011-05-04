#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "td3Utility.hpp"

using std::string;
using std::vector;
using std::ostringstream;
using string::npos;


string td3Utility::toString(int number, bool isFloat)
{
    ostringstream s;
    s << number;
    return s.str();
}

string td3Utility::toString(double number, bool isFloat)
{
    ostringstream s;
    s << number;
    return s.str();
}

vector<vector<string> > td3Utility::makeVector(string operand1, string operand2)
{
    vector<vector<string> > parameters;
    vector<string> subparameters;
    subparameters.push_back(operand1);
    parameters.push_back(subparameters);
    subparameters.clear();
    subparameters.push_back(operand2);
    parameters.push_back(subparameters);
    return parameters;
}

bool td3Utility::isFloat(string number)
{
    return (number.find(".") != npos);
}

int td3Utility::stoi(string number)
{
    return atoi(number.c_str());
}

double td3Utility::stof(string number)
{
    return atof(number.c_str());
}

