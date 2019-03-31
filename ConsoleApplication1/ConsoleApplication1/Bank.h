#pragma once
#include <string>
#include <iostream>
#include "Account.h"
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
class Bank
{
private:
	vector<Account> base;
public:
	Bank()
	{
		ifstream fin;
		fin.open("base.txt");
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				string f, i, o;
				string fio;
				fin >> f;
				fin >> i;
				fin >> o;
				fio = f + " " + i + " " + o;
				double money;
				fin >> money;
				string id;
				fin >> id;
				string type;
				fin >> type;
				Account buf = Account(fio, money, id, type);
				base.push_back(buf);
			}
			fin.close();
		}
		else
		{
			cout << "Файл с данными не найден" << endl;
		}
	}
	void Show()
	{
		for (int i = 0; i < base.size(); i++)
		{
			cout << left << setw(35) << base[i].Getfio() << setw(7) << base[i].Getmoney() << setw(15) << base[i].Getid() << setw(7) << base[i].Gettype() << endl;
		}
	}
};