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
//enumerator for fail and success
enum STATUS{FAIL,SUCCESS};
//global vector
vector<First> eu;
//constructor

ExistingUser::ExistingUser()
{
	name="NULL";//initilizing name with null
	password="NULL";//initilizing password with null

	First obj1;//object of class First 
	string name1;//to store name from database.txt
	string password1;//to store password from database.txt
	string mobile1;//to store mobile number from database.txt
	ifstream in("./../database/database.txt");//open file database.txt in read mode
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
		}
		else
			cout<<"other Exceptions"<<endl;
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

