#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "include/td3Math.hpp"
#include "include/td3Utility.hpp"
#include "include/testcases.hpp"

int output = 1; // 0 = none, 1 = errors, 2 = pretty

using namespace std;

int test(string);

int main()
{
    srand(time(NULL));
    td3Math::setFunctions("all");
    string ops [] = {"+","-","*","/","^","%"};
    int error = 0;
    for (unsigned int i = 0; i < 500; ++i)
        for (unsigned int j = 0; j < 6; ++j)
            error += test(ops[j]);
    return error;
}

template <typename T, typename Y>
string realResult(T op1, Y op2, string op)
{
    bool floating = !(op1 == floor(op1) && op2 == floor(op2));
    if (op == "+")
        return td3Utility::toString(op1 + op2, floating);
    else if (op == "-")
        return td3Utility::toString(op1 - op2, floating);
    else if (op == "*")
        return td3Utility::toString(op1 * op2, floating);
    else if (op == "/")
    {
        if (op2 != 0)
            return td3Utility::toString(op1 / op2, floating);
        else
            return "-nan";
    }
    else if (op == "^")
        return td3Utility::toString( pow((double)op1, op2), floating);
    else if (op == "%")
        return td3Utility::toString( fmod((double)op1, (double)op2), floating);
    else
        return "";
}

int test(string op)
{
    int error, totalErrors = 0;
    int i1 = testcases::randi(), i2 = testcases::randi(), i3 = testcases::randi(), i4 = testcases::randi();
    double d1 = testcases::randd(), d2 = testcases::randd(), d3 = testcases::randd(), d4 = testcases::randd();
    if (output == 2)
        cout << "Testing " << op << ": ";
    error = (td3Math::wrapper({{td3Utility::toString(i1,0)},{td3Utility::toString(i2,0)}},op) != realResult(i1,i2,op));
    totalErrors += error;
    if (error && output)
    {
        cout << endl << i1 << " " << op << " " << i2
             << endl << "  \"" 
             << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(i1,0),td3Utility::toString(i2,0)),op)
             << "\" should be \""
             << realResult(i1,i2,op) << "\"";
    }
    error = (td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(i3,0),td3Utility::toString(d1,1)),op) != realResult(i3,d1,op));
    totalErrors += error;
    if (error && output)
    {
        cout << endl << i3 << " " << op << " " << d1
             << endl << "  \""
             << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(i3,0),td3Utility::toString(d1,0)),op) 
             << "\" should be \"" 
             << realResult(i3,d1,op) << "\"";
    }
    error = (td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d2,1),td3Utility::toString(i4,0)),op) != realResult(d2,i4,op));
    totalErrors += error;
    if (error && output)
    {    
        cout << endl << d2 << " " << op << " " << i4
             << endl << "  \""
             << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d2,0),td3Utility::toString(i4,0)),op)
             << "\" should be \""
             << realResult(d2,i4,op) << "\"";
    }
    error = (td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d3,1),td3Utility::toString(d4,1)),op) != realResult(d3,d4,op));
    totalErrors += error;
    if (error && output)
    {
        cout << endl << d3 << " " << op << " " << d4
             << endl << "  \""
             << td3Math::wrapper(td3Utility::makeVector(td3Utility::toString(d3,0),td3Utility::toString(d4,0)),op)
             << "\" should be \""
             << realResult(d3,d4,op) << "\"";
    }
    if (totalErrors && output)
        cout << endl << totalErrors << " errors" << endl;
    if (output == 2)
        cout << endl;
    return totalErrors;
}
