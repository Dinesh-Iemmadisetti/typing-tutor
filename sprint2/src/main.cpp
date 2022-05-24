#include<iostream>
#include<stdio.h>
#include<stdio_ext.h>
#include<memory>
#include"NewUser.h"
#include"ExistingUser.h"
#include"TypeWriter.h"
using namespace std;
int main()
{
	int choice=0;
	while(1)
	{

		cout<<"\t\tWelcome to Type Writing\n\t\t__________________"<<endl;
		cout<<"1. New User registration"<<endl;
		cout<<"2. Existing User Login"<<endl;
		cout<<"3. Exit"<<endl;
		scanf("%d",&choice);
	//	cin>>choice;
		__fpurge(stdin);
		switch(choice)
		{
			case 1:
				NewUser *n;
				n=new NewUser; 
				n->add_user();
				delete n;
				break;
			case 2:
				ExistingUser *e;
				e=new ExistingUser();
				e->validate();
				delete e;
				break;
			case 3:
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
