#include"judge.h"
#include<iostream>
#include<fstream>
#define M 5
using namespace std;
void Judge::judge(string path, string file1, string file2)
{
    int flag=0;
    for (int x = 0; x < M; ++x)
    {
        output.clearOp1();
        output.clearOp2();
        input.inputGeneration(path);
        execute.execution(path,file1,1);
        execute.execution(path,file2,2);
        if (!output.outputComparison(path))
        {
            string inequalfile = "./output/inequal.csv";
            ofstream file(inequalfile, ios::app);
            if(!file) exit(-1);
            file << file1 + "," + file2<<endl;
            file.close();
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        string equalfile = "./output/equal.csv";
        ofstream file(equalfile, ios::app);
        if(!file) exit(-1);
        file << file1 + "," + file2<<endl;
        file.close();
    }
}