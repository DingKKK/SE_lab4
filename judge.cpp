#include"execute.h"
#include"judge.h"
#include"inputGeneration.h"
#include"outputComparison.h"
#include<iostream>
#include<fstream>
#define M 20
using namespace std;
void Judge::judge(string path, string file1, string file2)
{
    int flag=0;
    vector<string> op1;
    vector<string> op2;
    Input input;
    Output output;
    Execute execute;
    for (int x = 0; x < M; ++x)
    {
        op1.clear();
        op2.clear();
        input.inputGeneration(path);
        execute.execution(path,file1,op1);
        execute.execution(path,file2,op2);
        ofstream file22(path+"/out.txt",ios::app);
	    if (!file22) exit(-1);
        file22<<endl;
        if (!output.outputComparison(op1, op2))
        {
            string inequalfile = "/home/njucs/SE_lab4/output/inequal.csv";
            ofstream file(inequalfile, ios::app);
            file << file1 + "," + file2<<endl;
            file.close();
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        string equalfile = "/home/njucs/SE_lab4/output/equal.csv";
        ofstream file(equalfile, ios::app);
        file << file1 + "," + file2<<endl;
        file.close();
    }
}