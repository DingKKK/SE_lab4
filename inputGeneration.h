#define INPUT_GENERATION_H
#ifdef INPUT_GENERATION_H
#include<iostream>
using namespace std;
class Input
{
public:
    void inputGeneration(string path);
    string generator(int index, int left, int right);
};
#endif
