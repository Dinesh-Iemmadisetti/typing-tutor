#include<iostream>
#include<string>
#include"First.h"
using namespace std;

First::First()
{
	name="NULL";
	password="NULL";
	age=0;
	mobile="NULL";
}

void First :: setData(string name,string password,int age,string mobile)
{
	this->name=name;
        this->password=password;
        this->age=age;
        this->mobile=mobile;
}

string First :: getName()
{
	return name;
}

string First :: getMobile()
{
	return mobile;

}

string First :: getPassword()
{
	return password;
}

