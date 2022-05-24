#ifndef CLASS_NEW_USER_HEADER
enum STATUS{FAIL=0,SUCCESS};

#define CLASS_NEW_USER_HEADER
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class NewUser
{
private:
	string name;
	string password;
	int  age;
	string mobile;
public:	
	NewUser();
	void setNewUser(string name,string password,int age,string mobile)
	{
		this->name=name;
		this->password=password;
		this->age=age;
		this->mobile=mobile;
	}
	int WriteintoFile();
	int ageCheck();
	int mobileValidation();
	int add_user();
	int nameValidate();

};
#endif
