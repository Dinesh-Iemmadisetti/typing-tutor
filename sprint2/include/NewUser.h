/******************************
filename:NewUser.h
description:This class NewUser declares private variables and public methods to set the user given details
created by            date:
    Team-1            24-05-2022
********************************/

#ifndef __NEWUSER_HEADER__

#define __NEWUSER_HEADER__

#include<vector>
#include<string>
using namespace std;

enum STATUS{FAIL=0,SUCCESS};

/**************CLASS**********/

class NewUser
{

public:	
	NewUser();
	int WriteintoFile();                   //this function writes into the file
	int ageCheck();                        //this function validates the age
	int mobileValidation();                //this function validates the mobile number
	int add_user();                        //this function adds the user details
	int nameValidate();                    //this function validates the user name
private:
	string name; //stores username
	string password; //stores user password
	int  age; //stores user age
	string mobile; //stores user mobile

};
#endif
