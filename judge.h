#define JUDGE_H
#ifdef JUDGE_H
#include<vector>
#include<string>
#include<iostream>
#include"execute.h"
#include"inputGeneration.h"
#include"outputComparison.h"
using namespace std;
class Judge
{
private:
    Input input;
    Output output;
    Execute execute;
public:
    void judge(string path, string file1, string file2);
};
#endif