#include"outputComparison.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
void Output::outputConversion(string filename, vector<string>& output)
{
	ifstream file(filename, ios::in);
	if (!file) exit(-1);
	char temp[100];
	while (!(file.eof()))
	{
		file.getline(temp, 100);
		output.push_back(temp);
	}
	file.close();
}
bool Output::outputComparison(vector<string>& op1, vector<string>& op2)
{
	int i = 0;
	int j = 0;
	while (i < op1.size() && j < op2.size())
	{
		if (op1[i] == op2[j])
		{
			cout<<op1[i]<<" "<<op2[j]<<endl;
			op1.erase(op1.begin() + i);
			op2.erase(op2.begin() + j);
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	if (op1.size() == 0 || op2.size() == 0)
		return true;
	else
		return false;
}
