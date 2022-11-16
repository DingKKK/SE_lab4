#include<iostream>
#include"execute.h"
#include<string>
#include<fstream>
#include"outputComparison.h"
using namespace std;
void Execute::execution(string path, string filename, int index)
{
	string sh = path + "/shCommand.sh";
	string command="chmod u+x "+sh;
	system(command.c_str());
    shCommandGeneration(path, filename, index);
    system(sh.c_str());
} 
void Execute::shCommandGeneration(string path, string filename, int index)
{
    string inFormat = path + "/stdin_format.txt";
	string sh = path + "/shCommand.sh";
	ofstream file(sh, ios::out);
	if (!file) exit(-1);
	string command4 ="#! /bin/bash";
	file << command4 <<endl;
	string command1 = "g++ " + filename + " -o "+path+"/a.out";
	file << command1 << endl;
	string command2="chmod u+x "+path+"/a.out";
	file << command2 << endl;
	string command3;
	if(index==1)
		command3 = path+"/a.out <" + path + "/input.txt" + " >" + path + "/output1.txt 2>&1";
	else if(index==2)
		command3 = path+"/a.out <" + path + "/input.txt" + " >" + path + "/output2.txt 2>&1";
	file << command3;
	file.close();
}