#define OUTPUT_COMPARISON
#ifdef OUTPUT_COMPARISON
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Output
{
private:
    vector<string> op1;
    vector<string> op2;
public:
    void clearOp1(){op1.clear();}
    void clearOp2(){op2.clear();}
    void outputConversion(string filename,int index);
    bool outputComparison(string path);
};
#endif
