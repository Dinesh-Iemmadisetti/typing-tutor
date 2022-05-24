/******************************
filename:First.h
description:This class first declares private variables and public methods to set and get the user given details
created by            date:
    Team-1            24-05-2022
********************************/
#ifndef FIRST_CLASS_HEADER
#define FIRST_CLASS_HEADER
#include<iostream>
#include<string>
using namespace std;
//This class first sets the data 
class First
{
	string name; //stores the user name
	string password; //stores the user password
	int age; // stores the user age
	string mobile; // stores the user mobile number
public:
	First(); //constructor
	void setData(string name,string password,int age,string mobile); //this fuction takes the user details as arguments
	string getName(); //this function displays the username
	string getMobile(); //this function displays the mobilename
	string getPassword(); //this function displays the user password
};
#endif	
