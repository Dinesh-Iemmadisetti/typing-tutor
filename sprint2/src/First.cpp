/**********************************************************************************
**
** FILENAME : First.cpp
**
** DESCRIPTIION : 
**
**    CREATED BY                   DATE
**---------------------------------------------------------
** 	Team-1          	24-05-2022
**
********************************************************************************/
#include<iostream>
#include<string>
#include"First.h"
using namespace std;

/*********************************************************************
**
** Function NAME: First() 
**
** DESCRIPTION  : Declaring name,password,age,mobile for accessing.
**
** RETURNS : No return
**
**********************************************************************/
First::First()
{
	name="NULL";
	password="NULL";
	age=0;
	mobile="NULL";
}

/*********************************************************************
**
** Function NAME: setData(string name,string password,int age,string mobile) 
**
** DESCRIPTION  : Declaring Set function for name,password,age,mobile using string function.
**
** RETURNS : No return
**
**********************************************************************/
void First :: setData(string name,string password,int age,string mobile)
{
	this->name=name;
        this->password=password;
        this->age=age;
        this->mobile=mobile;
}

/*********************************************************************
**
** Function NAME: getName() 
**
** DESCRIPTION  : This Function gets name from User.
**
** RETURNS : No return
**
**********************************************************************/
string First :: getName()
{
	return name;
}

/*********************************************************************
**
** Function NAME: getMobile() 
**
** DESCRIPTION  : This Function gets Mobile number from User.
**
** RETURNS : No return
**
**********************************************************************/
string First :: getMobile()
{
	return mobile;

}

/*********************************************************************
**
** Function NAME: getPassword() 
**
** DESCRIPTION  : This Function gets Password from User.
**
** RETURNS : No return
**
**********************************************************************/
string First :: getPassword()
{
	return password;
}

