#ifndef CLASS_EXISTING_USER_HEADER
//enum STATUS{FAIL=0,SUCCESS};

#define CLASS_EXISTING_USER_HEADER
#include<iostream>
#include<string>
using namespace std;

class ExistingUser
{
	string name;
	string password;
	int nameAndPasswordValidation();
public:
	ExistingUser();
	int validate();
};
#endif
