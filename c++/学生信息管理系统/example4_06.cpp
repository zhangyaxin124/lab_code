/*************************************************
** 功能 : 学生成绩管理系统
** 作者 : Hui Yu
** 版本 : 2018-11-20 / 16:51
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
					cout << "查无此人！" << endl;
				else
					arr[i].Display();
				break;
			case 3:Outputstu(arr); break;
			case 4:
				if (Insertstu(arr))
				{
					cout << "成功插入一条记录！" << endl;
				}
				else
				{
					cout << "插入失败" << endl;
				}
				break;
			case 5:
				cout << "Input the name deleted: " << endl;
				cin >> na;
				if (Deletestu(arr, na))
					cout << "成功删除一条记录！" << endl;
				else
					cout << "删除失败！" << endl;
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
	cout << "********1.录入信息********" << endl;
	cout << "********2.查询信息********" << endl;
	cout << "********3.浏览信息********" << endl;
	cout << "********4.插入信息********" << endl;
	cout << "********5.删除信息********" << endl;
	cout << "********0.退    出********" << endl;
}

void Outputstu(const Student *arr)
{
	cout << "学生总人数 = " << Student::Getccount() << endl;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].Getage())    //保证是有效记录
			arr[i].Display();
	}
}
int Searchstu(const Student *arr, char *na)
{
	int i, j = N;
	for (i = 0; i < N; i++)
	{
		if (arr[i].Getage())     //保证是有效记录
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
			cout << "人数已满，无法继续录入" << endl;
		if (!arr[i].Getage())
			arr[i++].Input();
		cout << "继续输入嘛？（Y or N）" << endl;
		cin >> ch;
	} while (ch == 'Y');
}
bool Insertstu(Student *arr)
{
	if (Student::Getccount() == N)
	{
		cout << "人数已满，无法插入记录！" << endl;
		return false;
	}
	for (int i = 0; arr[i].Getage(); i++) //寻找第一个年龄为0的空位置,因为初始化对象age=0
	{
		arr[i].Insert();
	}
	return true;
}
bool Deletestu(Student *arr, char *na)
{
	if (Student::Getccount() == 0)
	{
		cout << "没有记录，无法删除！" << endl;
		return false;
	}
	int i = Searchstu(arr, na);   //查找函数，判断此人是否存在
	if (i == N)
	{
		cout << "查无此人！" << endl;
		return false;
	}
	arr[i].Delete();
	return true;
}
