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
#include <First.h>
#include <NewUser.h>
using namespace std;

#define MINAGE 7
#define MAXAGE 110
#define MOBILELENGTH 10
#define NOTFOUND -1
#define MAX 100
#define PASSWORDLENGTH 8

vector<First> nu; // globally declared vector of type first

/**********************************************************************************
**
** Constructor : NewUser
**
** DESCRIPTIION : constructor of newuser takes the data from the database text file in to 
                   the vector of type first.
**
** Return type : no return 
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
			throw FAIL;
		}
	}

	catch(STATUS x)
	{
		if(x==FAIL)
		{
			cout<<"\t database.txt file not exists"<<endl;
		//	exit(FAIL);
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
	
	if(this->age<MINAGE||this->age>MAXAGE)
	{
		cout<<"*** Age should not be less then 7 or greater then 110 ***"<<endl;
		return FAIL;
	}
	else
		return SUCCESS;



}
/**********************************************************************************
**
** Constructor : mobileValidation
**
** DESCRIPTIION : This function validates the mobile number
**
**  Return type : int
**
********************************************************************************/

int NewUser::mobileValidation()
{
	if(mobile.length()!=MOBILELENGTH)
	{
		
		cout<<"\t Invalid phone number try again\n";
		return FAIL;
	}
	else
	{
		int check=this->mobile.find_first_not_of("1234567890");
		if(check!=NOTFOUND)
		{
			cout<<"\t Invalid phone number try again\n";
			return FAIL;
 		}
		else
		{	
			for(First &f : nu)
			{
				if(f.getMobile()==this->mobile)
				{
					cout<<"\t Number already Exists"<<endl;
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
	int pos;//to store the postion of space
	pos=name.find(" ");//get the postion of space.
	if(pos == NOTFOUND)
	{
		for(First &d : nu)
		{
			if(d.getName()==this->name)
			{
				cout<<"\t Name Already Exists"<<endl;
				return FAIL;
			}
		}
	}
	else
	{
		cout<<"\t Spaces not allowed in Username "<<endl;
		return FAIL;
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
			throw FAIL;
		}
	}
	catch(STATUS x)
	{
		if(x == FAIL)
		{
			cout<<"\t database.txt file not found "<<endl;
			exit(FAIL);
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
	char data[MAX];
	cout<<"\n\n\t\t Enter the details to Register.\n\t\t --------------------------------\n "<<endl;
	A:cout<<"\t Enter Name without space     :";
	fgets(data,100,stdin);
	data[strlen(data)-1]='\0';
	name=data;
//	cin>>this->name;
//	__fpurge(stdin);
	if(SUCCESS!=nameValidate())
	{
			goto A;

	}

	P:cout<<"\t Enter Password(length should be 8 characters : ";
	cin>>this->password;
	__fpurge(stdin);
	

	if(password.length()!=PASSWORDLENGTH)
	{
		cout<<"\t password did not meet the character size"<<endl;
		goto P; 
	}

	G:cout<<"\t Enter Age        : ";
	cin>>age;
	__fpurge(stdin);

	if(SUCCESS!=ageCheck())
	{
		cout<<"\t Invalid age"<<endl;
		goto G;
	}

	M:cout<<"\t Enter Mobile No. : ";
	cin>>this->mobile;
	__fpurge(stdin);

	if(SUCCESS!=mobileValidation())
	{
		goto M;
	}

	if(SUCCESS==WriteintoFile())
	{
		cout<<"\t**** Successfully registered ****\n\n"<<endl;
		return SUCCESS;
	}
	else
	{
		cout<<"\t *** Not Registered ***\n"<<endl;
		return FAIL;
	}
	
	return SUCCESS;
}

