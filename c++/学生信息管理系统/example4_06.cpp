/*************************************************
** ���� : ѧ���ɼ�����ϵͳ
** ���� : Hui Yu
** �汾 : 2018-11-20 / 16:51
/**************************************************/
#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "example4_06_student.h"
using namespace std;

const int N = 10;

/*----------------------------------*
		  Main Function
*-----------------------------------*/
void menu();
void Outputstu(const Student *arr);
void Inputstu(Student *arr);
int Searchstu(const Student *arr, char *na);
bool Insertstu(Student *arr);
bool Deletestu(Student *arr, char *na);

int main()
{
	Student arr[N];
	int choice;
	char na[20];
	do
	{
		menu();
		cout << "Please input your choice:" << endl;
		cin >> choice;
		if (choice >= 0 && choice <= 5)
			switch (choice)
			{
			case 1:Inputstu(arr); break;
			case 2:
				cout << "Input the name searched: " << endl;
				cin >> na;
				int i;
				i = Searchstu(arr, na);
				if (i == N)
					cout << "���޴��ˣ�" << endl;
				else
					arr[i].Display();
				break;
			case 3:Outputstu(arr); break;
			case 4:
				if (Insertstu(arr))
				{
					cout << "�ɹ�����һ����¼��" << endl;
				}
				else
				{
					cout << "����ʧ��" << endl;
				}
				break;
			case 5:
				cout << "Input the name deleted: " << endl;
				cin >> na;
				if (Deletestu(arr, na))
					cout << "�ɹ�ɾ��һ����¼��" << endl;
				else
					cout << "ɾ��ʧ�ܣ�" << endl;
				break;
			default:break;
			}
	} while (choice);

	system("pause");

	return 0;
}

/*----------------------------------*
	  Main Function Definition
*-----------------------------------*/

void menu()
{
	cout << "********1.¼����Ϣ********" << endl;
	cout << "********2.��ѯ��Ϣ********" << endl;
	cout << "********3.�����Ϣ********" << endl;
	cout << "********4.������Ϣ********" << endl;
	cout << "********5.ɾ����Ϣ********" << endl;
	cout << "********0.��    ��********" << endl;
}

void Outputstu(const Student *arr)
{
	cout << "ѧ�������� = " << Student::Getccount() << endl;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].Getage())    //��֤����Ч��¼
			arr[i].Display();
	}
}
int Searchstu(const Student *arr, char *na)
{
	int i, j = N;
	for (i = 0; i < N; i++)
	{
		if (arr[i].Getage())     //��֤����Ч��¼
		{
			if (strcmp(arr[i].Getname(), na) == 0)
			{
				j = i;
				break;
			}
		}
	}
	return j;
}
void Inputstu(Student *arr)
{
	char ch;
	int i = 0;
	do
	{
		if (Student::Getccount() == N)
			cout << "�����������޷�����¼��" << endl;
		if (!arr[i].Getage())
			arr[i++].Input();
		cout << "�����������Y or N��" << endl;
		cin >> ch;
	} while (ch == 'Y');
}
bool Insertstu(Student *arr)
{
	if (Student::Getccount() == N)
	{
		cout << "�����������޷������¼��" << endl;
		return false;
	}
	for (int i = 0; arr[i].Getage(); i++) //Ѱ�ҵ�һ������Ϊ0�Ŀ�λ��,��Ϊ��ʼ������age=0
	{
		arr[i].Insert();
	}
	return true;
}
bool Deletestu(Student *arr, char *na)
{
	if (Student::Getccount() == 0)
	{
		cout << "û�м�¼���޷�ɾ����" << endl;
		return false;
	}
	int i = Searchstu(arr, na);   //���Һ������жϴ����Ƿ����
	if (i == N)
	{
		cout << "���޴��ˣ�" << endl;
		return false;
	}
	arr[i].Delete();
	return true;
}
