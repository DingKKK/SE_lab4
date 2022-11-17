#include<iostream>
#include<vector>
#include<string.h>
#include <dirent.h>
#include <stdlib.h>
#include<fstream>
#include<string>
#include"judge.h"
#define M 1
using namespace std;
int main()
{
	string p;
	cin >> p;
	string fatherPath="./"+p;	
	DIR* fatherDir;
	if (!(fatherDir = opendir(fatherPath.c_str()))) 
	{
		cout << "Fail to open father folder." << endl;
		exit(-1);
	}
	struct dirent* fatherPtr;
	struct dirent* ptr;	
	DIR* pDir;
	vector<string> filename;
	vector<string> path;
	while ((fatherPtr = readdir(fatherDir)) != 0) 
	{
		if (strcmp(fatherPtr->d_name, ".") != 0 && strcmp(fatherPtr->d_name, "..") != 0) 
		{
			path.push_back(fatherPath + "/" + fatherPtr->d_name);
		}
		
	}
	closedir(fatherDir);
	
	for(int x=0;x<path.size();++x)
	{
		filename.clear();
		if (!(pDir = opendir(path[x].c_str()))) 
		{
			cout << "Fail to open folder." << endl;
			exit(-1);
		}
		while ((ptr = readdir(pDir)) != 0) 
		{
			if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0) 
			{
				filename.push_back(path[x] + "/" + ptr->d_name);
			}
		}
		closedir(pDir);
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
					judge.judge(path[x],filename[i],filename[j]);
			}
		}
	}
}