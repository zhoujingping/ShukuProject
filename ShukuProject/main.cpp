// ShudoProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "Shuku.h"
#include<ctime>
#include<fstream>
#include <string>
#include <sstream>
#include <cstdlib>

//判断字符串是否只有数字
bool isnum(string s)
{
	stringstream sin(s);
	double d;
	char c;
	if (!(sin >> d))
		return false;
	if (sin >> c)
		return false;
	else
		return true;
}

int main(int argc,char** argv)
{
	int n;
	ofstream out("sudoku.txt");
	//判断输入是否合法
	if (argc == 3) 
	{
		if (strcmp(argv[1],"-c")==0) //-c：生成的数独棋盘的数量
		{
			if (!isnum(argv[2])) 
			{
				cout << "Error input parameter" << endl<<"Please re-enter an integer:";
				cin >> n;
			}
			else 
			{
				n = atoi(argv[2]);
			}
		}
		else
		{
			cout << "Error input parameter" << endl << "Please re-enter an integer:";
			cin >> n;
		}
	}
	else
	{
		cout << "Error input parameter" << endl << "Please re-enter an integer:";
		cin >> n;
	}
	//判断输入的数字是否为0
	while (n == 0) 
	{
		cout << "Error input parameter" << endl << "Please re-enter an integer:";
		cin >> n;
	}
	Shuku *sk=new Shuku[n];//动态生成n个数独
	srand(unsigned(time(NULL)));//产生随机数种子，防止每次产生的随机数相同
	for (int i = 0; i < n; i++) 
	{
		sk[i].GenerateShuku();
		sk[i].PrintShuku();
		sk[i].WriteFile(out);
		cout << endl;
		out << endl;
	}
	delete[] sk;
    return 0;
}

