#pragma once
/*************************************************
* Head File   : example4_06.h
* Create Time : 2018-11-20/16:48
/**************************************************/

#ifndef __EXAMPLE4_06_H__
#define __EXAMPLE4_06_H__

#include<iostream>
#include<cstring>
using namespace std;

#define SIZE 80

class Student
{
	char *name;
	char ID[19];
	char number[10];
	char speciality[20];
	int age;
	static int ccount; //实际有效的学生个数，小于等于对象的个数
public:
	Student();
	Student(char *na, char *id, char *num, char *spec, int ag);
	Student(const Student &per);
	~Student();
	char* Getname() const;//可以定义为常成员函数
	char* Getid();     //不可以定义为常成员函数
	char* Getnumber();     //不可以定义为常成员函数
	char* Getspec();     //不可以定义为常成员函数
	int Getage() const;
	void Display() const;
	void Input();
	void Insert();
	void Delete();
	static int Getccount();  //新增加的静态成员函数
};

#endif
