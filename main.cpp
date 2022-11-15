#include<iostream>
#include<vector>
#include<string.h>
#include <dirent.h>
#include <stdlib.h>
#include<fstream>
#include<string>
#include"execute.h"
#include"judge.h"
#include"inputGeneration.h"
#include"outputComparison.h"
#define M 1
using namespace std;
int main()
{
	string p;
	cin >> p;
	string path="/home/njucs/SE_lab4/input/"+p;
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
	Judge judge;
	for (int i = 0; i < filename.size() - 1; ++i)
	{
		if(filename[i][filename[i].length() - 1]!='p')
			continue;
		for (int j = i + 1; j < filename.size(); ++j)
		{
			
			if(filename[j][filename[j].length() - 1]!='p')
				continue;
            else
                judge.judge(path,filename[i],filename[j]);
		}
	}
}