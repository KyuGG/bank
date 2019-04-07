#pragma once
#include <string>
#include <iostream>
using namespace std;

class Account
{
private:
	string fio;
	double money;
	string id;
	string type; //debit, credit, deposit
public:
	Account()
	{
		fio = "";
		money = 0;
		id = "";
		type = "";
	}
	Account(string _fio, double _money, string _id, string _type)
	{
		fio = _fio;
		money = _money;
		id = _id;
		type = _type;
	}
	void AddMoney(double money_to_add)
	{
		if (money_to_add > 0)
		{
			money += money_to_add;
		}
		else
		{
			cout<<"Ошибка. Неверная сумма."<<endl;
		}
	}
	int Withdraw(double money_to_withdraw)
	{
		if (money_to_withdraw > 0)
		{
			if (money - money_to_withdraw < 0 && type == "credit")
			{
				money -= money_to_withdraw;
			}
			else
			{
				money -= money_to_withdraw;
			}
			return 0;
		}
		else
		{
			cout << "Ошибка. Неверная сумма." << endl;
			return -1;
		}
	}
	string Getfio()
	{
		return fio;
	}
	double Getmoney()
	{
		return money;
	}
	string Getid()
	{
		return id;
	}
	string Gettype()
	{
		return type;
	}
	
};