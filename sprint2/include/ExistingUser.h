/******************************
filename:ExistingUser.h
description:This class declares private and public variables and methods to validate the user give details
created by            date:
    Team-1            24-05-2022
********************************/

#ifndef __EXISTINGUSER_HEADER__

#define __EXISTINGUSER_HEADER__


#include<string>
using namespace std;

/*
existinguser class to validate the user given name and password
*/
class ExistingUser  
{
public:
	ExistingUser(); //constructor
	int validate(); //validates the user given data
private:
	string name; //stores the user name
	string password; // stores the user password
	int nameAndPasswordValidation(); //to validate the name and password
};
#endif
