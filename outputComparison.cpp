#include"outputComparison.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
void Output::outputConversion(string filename,int index)
{
	ifstream file(filename, ios::in);
	if (!file) exit(-1);
	char temp[100];
	while (!(file.eof()))
	{
		file.getline(temp, 100);
		if(index==1)
			op1.push_back(temp);
		else
			op2.push_back(temp);
	}
	file.close();
}
bool Output::outputComparison(string path)
{
	outputConversion(path+"/output1.txt",1);
	outputConversion(path+"/output2.txt",2);
	int i = 0;
	int j = 0;
	while (i < op1.size() && j < op2.size())
	{
		if (op1[i] != op2[j])
		{
			return false;
		}
		else
		{
			i++;
			j++;
		}
	}
	return true;
}
