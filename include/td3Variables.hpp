#ifndef TD3_VARIABLES_HPP_INCLUDED
#define TD3_VARIABLES_HPP_INCLUDED

#include <map>
#include <string>
#include <vector>

class td3Variables
{
    using std::map;
    using std::string;
    using std::vector;
private:
    struct less { bool operator() (vector< string > first, vector< string> second); };
    map< vector<string>,string, less> VarContainer;
    unsigned int currentDimensions(string name);
    bool contains(vector<string> needle, vector<string> haystack);
    bool caseInsensitiveCompare(vector< string > first, vector< string > second);
    static string toLower(string stol);
public:
    string getValue(vector<string> dimensions);
    string getValue(string name);
    void setValue(vector<string> dimensions, string value = "");
    void setValue(string name, string value = "");
    void unset(vector<string> dimensions);
    void unset(string name);
    bool isSet(vector<string> dimensions);
    bool isSet(string name);
    vector< vector< string > > nextDimension(vector<string> dimensions);
    vector< vector< string > > nextDimension(string name);

};

#endif // TD3_VARIABLES_HPP_INCLUDED
