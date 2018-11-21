#pragma warning(disable:4996)
#include"example4_06_student.h"
int Student::ccount = 0; //静态成员的初始化
Student::Student()
{
	name = NULL;
	age = 0;
}
Student::Student(char *na, char *id, char *num, char *spec, int ag)
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy(name, na);
	}
	strcpy(ID, id);
	strcpy(number, num);
	strcpy(speciality, spec);
	age = ag;
	ccount++;
}
Student::Student(const Student &per)
{
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	strcpy(ID, per.ID);
	strcpy(number, per.number);
	strcpy(speciality, per.speciality);
	age = per.age;
	ccount++;
}
Student::~Student()
{
	cout << "disCon" << endl;
	if (name)
	{
		delete[]name;
		ccount--;
	}
}
char* Student::Getname() const
{
	return name;
}
char* Student::Getid()
{
	return ID;
}
char* Student::Getnumber()
{
	return number;
}
char* Student::Getspec()
{
	return speciality;
}
int Student::Getage() const
{
	return age;
}
void Student::Display() const
{
	cout << "姓  名：" << name << endl;
	cout << "身份证：" << ID << endl;
	cout << "学  号：" << number << endl;
	cout << "专  业：" << speciality << endl;
	cout << "年  龄：" << age << endl;

}
void Student::Input()
{
	char na[10];
	cout << "输入姓  名：";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "输入身份证：";
	cin >> ID;
	cout << "输入年  龄：";
	cin >> age;
	cout << "输入专  业：";
	cin >> speciality;
	cout << "输入学  号：";
	cin >> number;
	ccount++;   //每输入一个，学生总数加1
}
void Student::Insert()
{
	if (!age)  //当对象的age成员值为0时，调用Input()函数重新输入对象的值
		Input();
}
void Student::Delete()
{
	age = 0;
	ccount--;
}
int Student::Getccount() //静态成员函数，用来访问静态数据成员
{
	return ccount;
}
