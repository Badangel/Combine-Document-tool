#ifndef CONBIMETXT_H
#define CONBIMETXT_H

#include <iostream>

#include <string>
#include<vector>
using namespace std;
class ConbimeTxt
{
public:
    ConbimeTxt();
    void getFiles(string path, vector<string>& files);
    void comBine(string filepath);
};

#endif // CONBIMETXT_H
