#ifndef CLASS_EXISTING_USER_HEADER
//enum STATUS{FAIL=0,SUCCESS};

#define CLASS_EXISTING_USER_HEADER
#include<iostream>
#include<string>
using namespace std;
/*
existinguser class to validate the user given name and password
*/
class ExistingUser  
{
	string name; //stores the user name
	string password; // stores the user password
	int nameAndPasswordValidation(); //to validate the name and password
public:
	ExistingUser(); //constructor
	int validate(); //validates the user given data
};
#endif
