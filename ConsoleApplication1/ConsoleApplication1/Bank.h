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
	~Bank()
	{
		bool y;
		cout << "Сохранить базу? 1/0: ";
		cin >> y;
		cout << endl;
		if (y == 1)
		{
			Save();
		}
	}
	void Show()
	{
		for (int i = 0; i < base.size(); i++)
		{
			cout << left << setw(35) << base[i].Getfio() << setw(7) << base[i].Getmoney() << setw(15) << base[i].Getid() << setw(7) << base[i].Gettype() << endl;
		}
	}
	void Save()
	{
		ofstream fout;
		fout.open("base.txt");
		for (int i = 0; i < base.size(); i++)
		{
			fout << left << setw(35) << base[i].Getfio() << setw(7) << base[i].Getmoney() << setw(15) << base[i].Getid() << setw(7) << base[i].Gettype() << endl;
		}
	}
	void AddAccount(Account acc)
	{
		bool s = true;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].Getid() == acc.Getid())
			{
				s = false;
			}
		}
		if (acc.Getid().length() == 10 && s == true)
		{
			base.push_back(acc);
		}
	}
	void RemoveAccount(string id_to_delete)
	{
		bool s = false;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].Getid() == id_to_delete)
			{
				base.erase(base.begin() + i);
				s = true;
			}
		}
		if (s == true)
		{
			cout << "Succesful!" << endl;
		}
		else
		{
			cout << "Nothing deleted" << endl;
		}
	}
	void Transfer(string from_id, string to_id, double sum)
	{
		int find_from = -1;
		int find_to = -1;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].Getid() == from_id)
			{
				find_from = i;
			}
			if (base[i].Getid() == to_id)
			{
				find_to = i;
			}
		}
		if (find_from != -1 && find_to != -1 && find_to != find_from)
		{
			int error = base[find_from].Withdraw(sum);
			if (error == 0) base[find_to].AddMoney(sum);
		}
	}
	void GroupShow()
	{
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].Gettype() == "debit")
			{
				cout << left << setw(35) << base[i].Getfio() << setw(7) << base[i].Getmoney() << setw(15) << base[i].Getid() << setw(7) << base[i].Gettype() << endl;
			}
		}
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].Gettype() == "deposit")
			{
				cout << left << setw(35) << base[i].Getfio() << setw(7) << base[i].Getmoney() << setw(15) << base[i].Getid() << setw(7) << base[i].Gettype() << endl;
			}
		}
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].Gettype() == "credit")
			{
				cout << left << setw(35) << base[i].Getfio() << setw(7) << base[i].Getmoney() << setw(15) << base[i].Getid() << setw(7) << base[i].Gettype() << endl;
			}
		}
	}
};