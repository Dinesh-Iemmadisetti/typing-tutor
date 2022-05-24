/******************************
filename:NewUser.h
description:This class NewUser declares private variables and public methods to set the user given details
created by            date:
    Team-1            24-05-2022
********************************/

#ifndef CLASS_NEW_USER_HEADER
enum STATUS{FAIL=0,SUCCESS};

#define CLASS_NEW_USER_HEADER
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/**************class**********/
class NewUser
{
private:
	string name; //stores username
	string password; //stores user password
	int  age; //stores user age
	string mobile; //stores user mobile
public:	
	NewUser();
	void setNewUser(string name,string password,int age,string mobile) //this function sets the user given details
	{
		this->name=name;               //stores username
		this->password=password;       //stores user password
		this->age=age;                 //stores user age
		this->mobile=mobile;           //stores user mobile
	}
	int WriteintoFile();                   //this function writes into the file
	int ageCheck();                        //this function validates the age
	int mobileValidation();                //this function validates the mobile number
	int add_user();                        //this function adds the user details
	int nameValidate();                    //this function validates the user name

};
#endif
