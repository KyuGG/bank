#include "pch.h"
#include <iostream>
#include <string>
#include "Bank.h"

using namespace std;
void ShowMenu()
{
	cout << "Банк" << endl;
	cout << "1. Открыть счет" << endl;
	cout << "2. Удаление счета" << endl;
	cout << "3. Сохранение данных" << endl;
	cout << "4. Денежный перевод между обычными счетами" << endl;
	cout << "5. Перевод с обычного счета на сберегательный и обратно" << endl;
	cout << "6. Сортировка" << endl;
	cout << "7. Группировка по типам вкладов" << endl;
	cout << "8. Информация о счетах" << endl;
	cout << "0. Выход" << endl;
}


void main()
{
	setlocale(LC_ALL, "Rus");
	system("color 7");
	Bank A;
	int ans = -1;
	while (ans != 0)
	{
		system("cls");
		ShowMenu();
		cin >> ans;
		switch(ans)
		{
			case 1:
			{
				string fio;
				double money;
				string id;
				string type;
				cout << "Введите ФИО: ";
				getline(cin, fio);
				getline(cin, fio);
				cout << endl << "Введите кол-во денег: ";
				cin >> money;
				cout << endl << "Введите id: ";
				cin >> id;
				cout << endl << "Введите тип карты(debit, credit, deposit): ";
				cin >> type;
				Account Acc = Account(fio, money, id, type);
				A.AddAccount(Acc);
				break;
			}
			case 2:
			{
				string id;
				cout << "Какой id: ";
				cin >> id;
				A.RemoveAccount(id);
			}
			case 3:
			{
				A.Save();
				break;
			}
			case 4:
			{
				string id1, id2;
				double sum;
				cout << "От кого и кому: ";
				cin >> id1 >> id2;
				cout << "Сколько: ";
				cin >> sum;
				A.Transfer(id1, id2, sum);
				break;
			}
			case 7:
			{
				A.GroupShow();
				break;
			}
			case 8:
			{
				A.Show();
				break;
			}
		};
		system("pause");
	}
	system("pause");
}