#include"execute.h"
#include"judge.h"
#include"inputGeneration.h"
#include"outputComparison.h"
#include<iostream>
#define M 1
using namespace std;
void Judge::judge(string path, string file1, string file2)
{
    int flag=0;
    vector<string> op1;
    vector<string> op2;
    for (int x = 0; x < M; ++x)
    {
        op1.clear();
        op2.clear();
        Input::inputGeneration(path);
        Execute::execution(path,file1,op1);
        Execute::execution(path,file2,op2);
        if (!Output::outputComparison(op1, op2))
        {
            string inequalfile = path + "/inequal.csv";
            ofstream file(inequalfile, ios::app);
            file << file1 + "," + file1<<endl;
            file.close();
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        string equalfile = path + "/equal.csv";
        ofstream file(equalfile, ios::app);
        file << file1 + "," + file1<<endl;
        file.close();
    }
}