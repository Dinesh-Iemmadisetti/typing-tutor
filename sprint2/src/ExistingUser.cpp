#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string>
#include<memory>
#include"ExistingUser.h"
#include"TypeWriter.h"
#include"Password.h"
#include"First.h"
using namespace std;
enum STATUS{FAIL,SUCCESS};

vector<First> eu;

ExistingUser::ExistingUser()
{
	name="NULL";
	password="NULL";

	First obj1;
	string name1;
	string password1;
	string mobile1;
	ifstream in("./../database/database.txt");
	try
	{
		if(in.is_open())
		{
			while(!in.eof())
                         {
				
				int age1=0;
				in>>name1;
	                        in>>password1;
                                in>>age1;
                                in>>mobile1;
                                if(in.eof())
                                    break;
				obj1.setData(name1,password1,age1,mobile1);
				eu.push_back(obj1);
			}
		in.close();
		}
		else
		{
			throw 1;
		}
	}

	catch(int x)
	{
		if(x==1)
		{
			cout<<"database.txt file not exists"<<endl;
			exit(0);
		}
	}


	
}

//existing user login 
int ExistingUser::nameAndPasswordValidation()
{
	
	for(First &d : eu)
	{
		if(d.getName()==this->name)
		{
	
			if(d.getPassword()==this->password)
			{
				cout<<"Login Successful"<<endl;
				return SUCCESS;
			}
			else
				return FAIL;
		}

	}
	return FAIL;

}
int ExistingUser::validate()
{
	int choice;
	A:cout<<"Login Page"<<endl;
	cout<<"Enter User name      :";
	__fpurge(stdin);
	cin>>this->name;
	__fpurge(stdin);
	password=getpass("Enter Password     :",true);
	if(SUCCESS==nameAndPasswordValidation())
	{
		unique_ptr<TypeWriter>t(new TypeWriter);
		if(t->typeCheckReport())
		{
			return FAIL;

		}
		else
		{
			return SUCCESS;
		}
	}
	else
	{
		cout<<"Invalid Login Credentials"<<endl;
		cout<<"1.To Try again\npress any key to exit"<<endl;
	//	cin>>choice;
		scanf("%d",&choice);
		__fpurge(stdin);
		if(choice==1)
			goto A;
		else 
			return FAIL;
	
	}
}

