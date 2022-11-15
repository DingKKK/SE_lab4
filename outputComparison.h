#define OUTPUT_COMPARISON
#ifdef OUTPUT_COMPARISON
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Output
{
public:
    void outputConversion(string filename, vector<string>& output);
    bool outputComparison(vector<string>& op1,vector<string>& op2);
};
#endif
