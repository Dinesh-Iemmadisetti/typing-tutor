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
#include"NewUser.h"
#include"ExistingUser.h"
#include"TypeWriter.h"
using namespace std;
#define nu 1 //macros for newuser
#define eu 2 //macros for existinguser
#define ex 3 //macros to exit
/******************************************************************************
**
** FUNCTION NAME : main
**
**DESCRIPTION : execution of program starts from main function
**
**RETURNS : returns 0 on successful execution.
**
*****************************************************************************/
int main()
{
	int choice=0;
	while(1)
	{

		cout<<"\t\tWelcome to Type Writing\n\t\t__________________"<<endl;
		cout<<"\t1. New User registration"<<endl;
		cout<<"\t2. Existing User Login"<<endl;
		cout<<"\t3. Exit"<<endl;
		cout<<"\t Enter your choice : ";
		scanf("%d",&choice);
		__fpurge(stdin);
		switch(choice)
		{
			case nu:
				NewUser *n;
				n=new NewUser; 
				n->add_user();
				delete n;
				break;
			case eu:
				ExistingUser *e;
				e=new ExistingUser();
				e->validate();
				delete e;
				break;
			case ex:
				cout<<"Exit"<<endl;
				break;
			default:
				cout<<"Invalid option\n"<<endl;
		}
	if(choice==3)
		break;
	}
	return 0;
}
