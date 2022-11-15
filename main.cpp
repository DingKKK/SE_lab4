#include<iostream>
#include<vector>
#include<string.h>
#include <dirent.h>
#include <stdlib.h>
#include<fstream>
#include<string>
#include"execute.h"
#include"inputGeneration.h"
#include"outputComparison.h"
#define M 1
using namespace std;
void shCommandGeneration(string path, string filename);
int main()
{
	string p;
	cin >> p;
	string path="/home/njucs/SE_lab/blog/input/"+p;
	vector<string> filename;
	DIR* pDir;
	if (!(pDir = opendir(path.c_str()))) 
	{
		cout << "Fail to open folder." << endl;
		exit(-1);
	}
	struct dirent* ptr;
	while ((ptr = readdir(pDir)) != 0) 
	{
		if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0) 
		{
			filename.push_back(path + "/" + ptr->d_name);
		}
	}
	closedir(pDir);
	int flag=0;
	vector<string> op1;
	vector<string> op2;
	for (int i = 0; i < filename.size() - 1; ++i)
	{
		if(filename[i][filename[i].length() - 1]!='p')
			continue;
		for (int j = i + 1; j < filename.size(); ++j)
		{
			flag=0;
			if(filename[j][filename[j].length() - 1]!='p')
				continue;
			for (int x = 0; x < M; ++x)
			{
				Input::inputGeneration(path);
				Execute::execution(path,filename[i],op1);
				Execute::execution(path,filename[j],op2);
				if (!Output::outputComparison(op1, op2))
				{
					string inequalfile = path + "/inequal.csv";
					ofstream file(inequalfile, ios::app);
					file << filename[i] + "," + filename[j]<<endl;
					file.close();
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				string equalfile = path + "/equal.csv";
				ofstream file(equalfile, ios::app);
				file << filename[i] + "," + filename[j]<<endl;
				file.close();
			}
		}
	}
}