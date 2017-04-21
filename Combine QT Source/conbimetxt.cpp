#include "conbimetxt.h"
#include <io.h>
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

ConbimeTxt::ConbimeTxt()
{

}

void ConbimeTxt::getFiles(string path, vector<string>& files) {
   // cout<<"111"<<endl;
    //文件句柄
    long   hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
        //cout<<"222"<<endl;
        do {
            //如果是目录,迭代之
            //如果不是,加入列表
            if ((fileinfo.attrib &  _A_SUBDIR)) {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            else {
               // cout<<"addfile"<<endl;
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

void ConbimeTxt::comBine(string filepath)
{
    vector<string> files;

        ConbimeTxt t;
        /////获取该路径下的所有文件
        t.getFiles(filepath, files);

        char str[30];
        int n = files.size();
        for (int i = 0; i < n; i++) {
            cout <<i<<"file:"<<files[i]<<endl;
        }
       // cout <<"?????????????"<<n<<endl;
        ifstream fin;
        ofstream fout("merge.txt");
        for (int i = 0; i < n; i++) {
            fin.open(files[i].c_str());
            string a;
            //cout << i << "copy个文件" << files[i] << endl;
            fout <<""<< files[i] << "\n";
            //fout<<i<<"\n";
            while (getline(fin, a, '\n')) {
                fout<<a<<"\n";
                //cout<<"copy"<<a;
            }
            fin.close();
            fin.clear();
        }
}
