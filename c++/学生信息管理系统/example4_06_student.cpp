#pragma warning(disable:4996)
#include"example4_06_student.h"
int Student::ccount = 0; //��̬��Ա�ĳ�ʼ��
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
	cout << "��  ����" << name << endl;
	cout << "���֤��" << ID << endl;
	cout << "ѧ  �ţ�" << number << endl;
	cout << "ר  ҵ��" << speciality << endl;
	cout << "��  �䣺" << age << endl;

}
void Student::Input()
{
	char na[10];
	cout << "������  ����";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "�������֤��";
	cin >> ID;
	cout << "������  �䣺";
	cin >> age;
	cout << "����ר  ҵ��";
	cin >> speciality;
	cout << "����ѧ  �ţ�";
	cin >> number;
	ccount++;   //ÿ����һ����ѧ��������1
}
void Student::Insert()
{
	if (!age)  //�������age��ԱֵΪ0ʱ������Input()����������������ֵ
		Input();
}
void Student::Delete()
{
	age = 0;
	ccount--;
}
int Student::Getccount() //��̬��Ա�������������ʾ�̬���ݳ�Ա
{
	return ccount;
}
