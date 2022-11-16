#define EXECUTE_H
#ifdef EXECUTE_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Execute
{
public:
    void execution(string path, string filename, int index);
    void shCommandGeneration(string path, string filename, int index);
};
#endif