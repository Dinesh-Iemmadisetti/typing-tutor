#ifndef FIRST_CLASS_HEADER
#define FIRST_CLASS_HEADER
#include<iostream>
#include<string>
using namespace std;
class First
{
	string name;
	string password;
	int age;
	string mobile;
public:
	First();
	void setData(string name,string password,int age,string mobile);
	string getName();
	string getMobile();
	string getPassword();
};
#endif	
