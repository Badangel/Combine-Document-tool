#include <io.h>
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

void getFiles(string path, vector<string>& files) {
	//�ļ����
	long   hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			//�����Ŀ¼,����֮
			//�������,�����б�
			if ((fileinfo.attrib &  _A_SUBDIR)) {
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else {
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
int main() {
	char * filePath = "D:\\С����\\srcCode";
	vector<string> files;

	/////��ȡ��·���µ������ļ�
	getFiles(filePath, files);

	char str[30];
	int n = files.size();
	for (int i = 0; i < n; i++) {
		cout <<i<<"���ļ�"<<files[i]<<endl;
	}
	ifstream fin;
	ofstream fout("merge.txt");
	for (int i = 0; i < n; i++) {
		fin.open(files[i]);
		string a;
		//cout << i << "copy���ļ�" << files[i] << endl;
		fout <<"\n\n\n!!!!!"<< files[i] << "\n";
		//fout<<i<<"\n";
		while (getline(fin, a, '\n')) {
			fout<<a<<"\n";
			//cout<<"copy"<<a;
		}
		fin.close();
		fin.clear();
	}
	cin.get();
	cin.get();
	return 0;
}
