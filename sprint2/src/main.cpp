/**********************************************************************************
**
** FILENAME : main.cpp
**
** DESCRIPTIION : Display the menu to user
** 
**    CREATED BY                 DATE
**---------------------------------------------------------
** Team-1                       24-05-2022
**
********************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdio_ext.h>
#include<memory>
#include <NewUser.h>
#include <ExistingUser.h>
#include <TypeWriter.h>
using namespace std;

#define NUMACRO '1' //macros for newuser
#define EUMACRO '2' //macros for existinguser
#define EXMACRO '3' //macros to exit

/******************************************************************************
**
** FUNCTION NAME : main
**
** DESCRIPTION : execution of program starts from main function
**
** RETURNS : returns 0 on successful execution.
**
*****************************************************************************/

int main()
{
	char choice;
	bool flag=false;
//	NewUser *n=new NewUser();
//	ExistingUser *e=new ExistingUser();
	
	while(!flag)
	{

		cout<<"\t\tWelcome to Type Writing\n\t\t______________________"<<endl;
		cout<<"\t 1. New User registration"<<endl;
		cout<<"\t 2. Existing User Login"<<endl;
		cout<<"\t 3. Exit"<<endl;
		cout<<"\t Enter your choice : ";
		scanf("%c",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case NUMACRO:
				NewUser *newObject;
				newObject=new NewUser(); 
				newObject->add_user();
			//	delete newObject;
				break;
			case EUMACRO:
				ExistingUser *existingObject;
				existingObject=new ExistingUser();
				existingObject->validate();
			//	delete existingObject;
				break;
			case EXMACRO:
				cout<<"  Exit"<<endl;
				flag=true;
				break;
			default:
				cout<<"\t Invalid option\n"<<endl;
		}

	}
	return 0;
}
