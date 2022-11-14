#include"inputGeneration.h"
#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
using namespace std;
void input::inputGeneration(string path)
{
	string ifile = path + "/input.txt";
	ofstream inputfile(ifile, ios::out);
	if (!inputfile) exit(-1);
	string sfile = path + "/stdin_format.txt";
	ifstream stdinfile(sfile, ios::in);
	if (!stdinfile) exit(-1);
	char temp[100];
	ostringstream buf;
	buf<<stdinfile.rdbuf()<<ends;
	string str=buf.str();
	for(int x=0;str[x]!='\0';++x)
	{
		if(buf.str()[x]==' ')
			continue;
		if(x==0||(x>0&&str[x-1]==' '))
		{
			string index;
			int j = 0;
			int i = x;
			char t1[20];
			for (i=x; str[i] != '('; ++i)
			{
				t1[j] = str[i];
				j++;
			}
			t1[j]='\0';
			index=t1;
			i++;
			int left = 0;
			int right = 0;
			if (index != "char")
			{
				char l1[10];
				char r1[10];
				string l, r;
				j = 0;
				for (; str[i] != ','; ++i)
				{
					l1[j] = str[i];
					j++;
				}
				i++;
				l1[j]='\0';
				l=l1;
				j = 0;
				for (; str[i] != ')'; ++i)
				{
					r1[j] = str[i];
					j++;
				}
				r1[j]='\0';
				r=r1;
				left = stoi(l);
				right = stoi(r);
			}
			string input=generator(index.length(), left, right);
			inputfile << input<<endl;
		}
	}
	stdinfile.close();
	inputfile.close();
}
string input::generator(int index, int left, int right)
{
	switch (index)
	{
	case 3: {
		int in = (rand() % (right - left + 1)) + left;
		return to_string(in);
	}
	case 4: {
		left = 'A';
		right = 'z';
		int ch = (rand() % (right - left + 1)) + left;
		string temp;
		temp[0] = 'A' + ch - 48;
		return temp;
	}
	case 5: {
		int len = (rand() % (right - left + 1)) + left;
		string temp;
		int l = 'A';
		int r = 'z';
		for (int i = 0; i < len; ++i)
		{
			int ch = (rand() % (r - l + 1)) + l;
			temp[i] = 'A' + ch - 48;
		}
		return temp;
	}
	}
}