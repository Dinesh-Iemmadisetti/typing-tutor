/**********************************************************************************
**
** FILENAME : NewUser.cpp
**
** DESCRIPTIION : This file takes the details from user like username,password,age,mobile number 
**                  and stores these details to database.
**    CREATED BY                   DATE
**---------------------------------------------------------
**     Team-1          		24-05-2022
**
********************************************************************************/
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

vector<First> nu; // globally declared vector of type first

/**********************************************************************************
**
**constructor : NewUser
**
** DESCRIPTIION : constructor of newuser takes the data from the database text file in to 
                   the vector of type first.
**
**  Return type : no return 
**
********************************************************************************/

NewUser::NewUser()
{
	name="NULL"; //initilise name to NULL
	password="NULL";//initilise password to null
	age=0;//initilise age to zero
	mobile="NULL";//initilise mobile to null

	First obj;// obj of class first

	string name1;//to store name from database
	string password1;//to store password from database
	string mobile1;//to store mobile from database
	ifstream in("./../database/database.txt");//open the database.txt file in read mode
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
			exit(0);
		}
	}
}

/**********************************************************************************
**
** function : ageCheck
**
** DESCRIPTIION : This function validates the user given age
**
**  Return type : int
**
********************************************************************************/

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
/**********************************************************************************
**
**constructor : mobileValidation
**
** DESCRIPTIION : This function validates the mobile number
**
**  Return type : int
**
********************************************************************************/

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

/**********************************************************************************
**
**function name:nameValidate
**
** DESCRIPTIION : This function validates the name  
               
**
**  Return type :int
**
********************************************************************************/


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

/**********************************************************************************
**
**function name : WriteintoFile
 **
** DESCRIPTIION : This function writes the user details into database file 
 **
**  Return type : int
**
********************************************************************************/

int NewUser :: WriteintoFile()
{
	
	ofstream w;//object of output stream
	w.open("./../database/database.txt",ios::app);//open the file in append mode
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
			exit(0);
		//	return FAIL;
		}
		return FAIL;
	}

}

/**********************************************************************************
**
*function name : add_user
**
** DESCRIPTIION : This function takes all the user details from the user
**
**  Return type : int
**
********************************************************************************/

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

