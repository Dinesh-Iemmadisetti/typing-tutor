#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string>
#include<memory>
#include"First.h"
#include"NewUser.h"
using namespace std;

vector<First> nu;

NewUser::NewUser()
{
	name="NULL";
	password="NULL";
	age=0;
	mobile="NULL";

	First obj;

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
				obj.setData(name1,password1,age1,mobile1);
				nu.push_back(obj);

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
			cout<<"other"<<endl;
	}
}

int NewUser::ageCheck()
{
	
	if(this->age<7||this->age>110)
	{
		cout<<"age should not be less then 7 or greater then 110"<<endl;
		return FAIL;
	}
	else
		return SUCCESS;



}

int NewUser::mobileValidation()
{
	if(mobile.length()!=10)
	{
		
		cout<<"invalid phone number try again\n";
		return FAIL;
	}
//	else if(mobile.length()==10)
	else
	{
		int check=this->mobile.find_first_not_of("1234567890");
		if(check!=-1)
		{
			cout<<"invalid phone number try again\n";
			return FAIL;
 		}
		else
		{	
			for(First &f : nu)
			{
				if(f.getMobile()==this->mobile)
				{
					cout<<"Number already Exists"<<endl;
					return FAIL;
				}
			}
		}
	}
	return SUCCESS;
}

int NewUser::nameValidate()
{
	
	for(First &d : nu)
	{
		if(d.getName()==this->name)
		{
			cout<<"Name already Taken"<<endl;
			return FAIL;
		}
	}
	return SUCCESS;

}

int NewUser :: WriteintoFile()
{
	
	ofstream w;
	w.open("./../database/database.txt",ios::app);
	try
	{
		if(w.is_open())
		{
			w<<name<<" "<<password<<" "<<age<<" "<<mobile<<endl;
			w.close();
			return SUCCESS;
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
			cout<<"database.txt"<<endl;
			return FAIL;
		}
			return FAIL;
	}

}

int NewUser::add_user()
{
	cout<<"\tEnter the details to create Account\n"<<endl;
	A:cout<<"Enter Name      :";
	cin>>this->name;
	__fpurge(stdin);
	if(SUCCESS!=nameValidate())
	{
			goto A;

	}

	P:cout<<"Enter Password(length should be 8 characters :";
	cin>>this->password;
	__fpurge(stdin);
	

	if(password.length()!=8)
	{
		cout<<"password did not meet the character size"<<endl;
		goto P; 
	}

	G:cout<<"Enter Age        :";
	cin>>age;
	__fpurge(stdin);

	if(SUCCESS!=ageCheck())
	{
		cout<<"Invalid age"<<endl;
		goto G;
	}

	M:cout<<"Enter Mobile No. :";
	cin>>this->mobile;
	__fpurge(stdin);

	if(SUCCESS!=mobileValidation())
	{
		goto M;
	}

	if(SUCCESS==WriteintoFile())
	{
		cout<<"Sucessfully registered "<<endl;
		return SUCCESS;
	}
	else
	{
		cout<<"Not Registered"<<endl;
		return FAIL;
	}
	
	return SUCCESS;
}

