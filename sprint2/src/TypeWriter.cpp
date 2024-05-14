/**********************************************************************************
**
** FILENAME : TypeWriter.cpp
**
** DESCRIPTIION :It will show the difficulty options and user can select from it and start typing at the and it will show WPM,accuracy of wrong letters,accuracy 
		  of correct letters and WPM(words per minute) of file.
**
**    CREATED BY                  DATE
**---------------------------------------------------------
**      Team-1          	24-05-2022
**
********************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<stdio_ext.h>
#include<string>
#include<memory>
#include<stdexcept>
#include <TypeWriter.h>
//enumerator faii=0 success=1
using namespace std;

enum STATUS{FAIL,SUCCESS};
vector<float>Each_line;
float ewrong=0;
float ecorrect=0;

#define EASY '1'
#define MODERATE '2'
#define DIFFICULT '3'
#define MAX 100
#define NOTFOUND -1
//TypeWriter constructor initilizing data variables with zero
/*********************************************************************
**
** Typewriter NAME: TypeWriter() 
**
** DESCRIPTION : TypeWriter constructor initilizing data variables with zero
**
** RETURNS: no return
**
**********************************************************************/

TypeWriter::TypeWriter()
{
	correct_words=0;
	wrong_words=0;
        correct_letters=0;
        wrong_letters=0;
	total=0;
}

/*********************************************************************
**
** FUNCTION NAME : wordsAndLettersCompare
**
** DESCRIPTION : This function compares words and letters of two given string
**
** RETURNS: int
**
**********************************************************************/

int TypeWriter :: wordsAndLettersCompare(string tok1 , string tok)
{

	if(tok1.length()<tok.length())
	{
		for(unsigned int i=0;i<tok1.length();i++)
		{
			if(tok1[i]==tok[i])
			{
				++correct_letters;
		//		cout<<"\t correct_letters : "<<correct_letters<<endl;
			}
			else
			{
			++wrong_letters;
		//	cout<<"\twrong_letters : "<<wrong_letters<<endl;
			}
		}
			wrong_letters+= (int)tok.length() - (int)tok1.length();
		}
		else if(tok1.length() > tok.length())
		{
			for(unsigned int i=0;i<tok.length();i++)
			{
				if(tok[i]==tok1[i])
				{
					++correct_letters;
		//					cout<<"\t correct_letters : "<<correct_letters<<endl;
				}
				else
				{
					++wrong_letters;
//						cout<<"\t wrong_letters : "<<wrong_letters<<endl;
				}
			}
		}
		else if(tok1.length()==tok.length())
		{
			for(unsigned int i=0;i < tok.length() ;i++)
			{
		//							cout<<tok[i]<<" :  "<<tok1[i]<<endl;
				if(tok[i]==tok1[i])
				{
					++correct_letters;
		//								cout<<"correct_letters : "<<correct_letters<<endl;
				}
				else
				{
					++wrong_letters;
		//								cout<<"wrong_letters : "<<wrong_letters<<endl;
				}
			}
		}
	wrong_words++;

	return SUCCESS;
		//					cout<<"Wrong : "<<wrong_words<<endl;
}

/*********************************************************************
**
** FUNCTION NAME :setZero
**
** DESCRIPTION : This function declares all the data members to zero
**
** RETURNS: int
**
**********************************************************************/

int TypeWriter :: setZero()
{
	wrong_words=0;
	correct_words=0;
	wrong_letters=0;
	correct_letters=0;
	total=0;
	return SUCCESS;
}

/*********************************************************************
**
** FUNCTION NAME : selectDifficulty
**
** DESCRIPTION : This function allows to select the difficulty levels
**
** RETURNS: fstream
**
**********************************************************************/

fstream TypeWriter :: selectDifficulty()
{
	char choice;//to select the text file
	A:cout<<"\nSelect Difficulty Levels"<<endl<<endl;
	cout<<"** 1.Easy"<<endl;
	cout<<"** 2.Moderate"<<endl;
	cout<<"** 3.Difficult"<<endl;
	cout<<"\n Enter the choice : ";
	cin>>choice;
	__fpurge(stdin);
	if(choice==EASY)
	{
		fstream select;//to read the text file
		try
		{
			select.open("./../text/easy.txt",ios::in|ios::out);
			if(select.is_open())
			   {
                		return select;
			   }
			   else
			   	throw FAIL;
			   
    		 }
		catch(STATUS x)
		   {
				cout<<"\t easy.txt file not found"<<endl;
				exit(FAIL);
		   }
	}
        else if(choice==MODERATE)
        {
               fstream select;//to read the text file
		try
		{
               		select.open("./../text/medium.txt",ios::in|ios::out);
			if(select.is_open())
			{
               			return select;
			}
			else
				throw FAIL;
		}
		catch(STATUS x)
		{
			cout<<"\t medium.txt file not found"<<endl;
			exit(FAIL);
		}
        }
        else if(choice==DIFFICULT)
        {
              fstream select;//to read the text file
		try
		{
             		 select.open("./../text/hard.txt",ios::in|ios::out);
			if(select.is_open())
			{
              			return select;
			}
			else
				throw FAIL;
		}
		catch(STATUS x)
		{
			cout<<"\t hard.txt file not found"<<endl;
			exit(FAIL);
		}
		
        }
	else
	{
		cout<<"invalid option\nChoose from below menu"<<endl;
		goto A;
	}
	
}

/*********************************************************************
**
** FUNCTION NAME :typeCheckReport
**
** DESCRIPTION :This function displays the words per minute ans accuracy of 
               correct letters and wrong letters
**
** RETURNS: int
**
**********************************************************************/

int TypeWriter :: showResults()
{	
	cout<<"\n\t\tResults\n\t\t_______\n"<<endl;
	vector<float>::iterator start;
	int init=1;
	start=Each_line.begin();
	cout<<"\n\tEach line result\n\t______\n"<<endl;
	while(start!=Each_line.end())
	{
		
		cout<<"  Line no :"<<init<<"\n\twrong words :"<<*start<<"  correct words :"<<*(start+1)<<"  WPM :"<<*(start +2)<<endl;;
		start=start+3;
		++init;
	}
	Each_line.clear();
	cout<<"\n"<<endl;
	
	cout<<"  Total Correct words                                  : "<<correct_words<<endl;
	cout<<"  Total  Wrong words                                   : "<<wrong_words<<endl;
	cout<<"  Wrong letters of entire text file                    : "<<wrong_letters<<endl;
	cout<<"  Correct letters of entire text file                  : "<<correct_letters<<endl;
	cout<<"  Accuracy of Wrong letters for the entire Text file   : "<<(wrong_letters*100.00f)/(wrong_letters + correct_letters)<<endl;
	cout<<"  Accuracy of correct letters for the entire Text file : "<<(100.00f-(wrong_letters*100.00f)/(wrong_letters + correct_letters))<<endl;
      //	cout<<"Total secs"<<total<<endl;
	try
	{
		if(correct_words==0)
			throw correct_words;
		else
		cout<<"\n  Words Per Minutes for the entire Text file           : "<<(60.00f/((float)total/(correct_words)))<<endl;
	}
	catch(int x)
	{
		cout<<"\n  No correct words are written\n";
		cout<<"\n  WPM(Words per Minutes) is 0"<<endl;
	}
	return SUCCESS;
}

int TypeWriter::typeCheckReport()
{
	B:
	bool flag=false;
	char choice;
	float wrong_words_each_line=0;
	float correct_words_each_line=0;						//to select retry or exit
	char line[MAX];					//store the lines of text files
	char write[MAX];				//store user written line
	time_t start=0,end=0,time_per_line=0;		//star time,end time,time per line,total time
	float c_word=0;					//count word per each line
	float c_line=0;					//count correct lines
	float wpm=0;					//words per minute
	float l_num=0;					//to show line numbers for text file data
	float w_line=0;					//cout wrong line count
	string s1;					//string to store write
	fstream inout;					//fstream obj to store return value of selectDifficulty
	inout=selectDifficulty();			//stroing the return type

		while(!inout.eof())
		{
			
			inout.getline(line,MAX);
			//show the lines to write
			__fpurge(stdin);

			if(inout.eof())
				break;

			++l_num;
			cout<<"\n\t Line no "<<l_num<<" :"<<line<<endl;
			start=time(NULL);
			cout<<"\t Type here :";
			fgets(write,MAX,stdin);
			write[strlen(write)-1]='\0';
			string s2(write);
			if(s2.compare(line)==0)
			{
				c_line++;
			}
			else
			{
				w_line++;
			}
			string l1=line;
			int pos=0;
			int pos1=0;
			string tok1;
			string tok;
			while(!flag)
			{
				pos=l1.find(" ");
				if(pos!=NOTFOUND)
				{
					tok=l1.substr(0,pos);
					l1.erase(0,pos+1);
					A:pos1=s2.find(" ");
					if(pos1!=NOTFOUND)
					{
						tok1=s2.substr(0,pos1);
						if(tok1.empty())
						{
						s2.erase(0,pos1+1);
						goto A;
						}
						s2.erase(0,pos1+1);
						if(tok.compare(tok1)==0)
						{
							correct_words++;
							c_word++;
							correct_letters += tok.length();
						}
						else
						{
							try
							{
								if(SUCCESS!=wordsAndLettersCompare(tok1 , tok))
								{
										throw FAIL;	
								}
							}
							catch(STATUS x)
							{
								if(x==FAIL)
								{
									cout<<"\t Exception Occured"<<endl;
								}

							}
						}
					}
					else
					{
						if(s2.length()!=0)
						{
							
							if(tok.compare(s2)==0)
							{
								correct_words++;
								c_word++;
								correct_letters += tok.length();
							}
							else
							{
								
								try
								{
									if(SUCCESS!=wordsAndLettersCompare(s2 , tok))
									{
											throw FAIL;		
									}
								}
								catch(STATUS x)
								{
									if(x==FAIL)
									{
										cout<<"\t Exception Occured"<<endl;
									}

								}
							
							}
							s2.erase();
						}
						else if(s2.empty())
						{
							wrong_words++;
							wrong_letters+=tok.length();
						}
					}
				
						
				}
				else 	
				{
					if(l1.compare(s2)==0)
					{
						correct_words++;
						c_word++;
						correct_letters += l1.length();
					}
					else 
					{
						if(s2.length()!=0)
						{
						
							try
							{
								if(SUCCESS!=wordsAndLettersCompare( s2 , l1))
								{
										throw FAIL;	
								}
							}
							catch(STATUS x)
							{
								if(x==FAIL)
								{
									cout<<"\t Exception Occured"<<endl;
								}

							}
						}

						else if(s2.empty())
						{
							wrong_letters+=l1.length();
							wrong_words++;
						}
					}
					end=time(NULL);
					time_per_line=end-start;
					break;
				}
		
                  }			
			try
			{
				if(time_per_line==0)
					throw time_per_line;
				else
					wpm=((c_word)*60)/time_per_line;
	
			}
			catch(long int g)
			{
				cout<<"\t Divide by zero error"<<endl;
				time_per_line=1;
				wpm=(c_word * 60)/1;
			}

			cout<<"\n** Words Per Minute for the line :"<<wpm<<endl;
			cout<<"\n***************************************"<<endl;
			c_word=0;
			total+=time_per_line;
			wrong_words_each_line = wrong_words - ewrong;
			ewrong=wrong_words;
			correct_words_each_line = correct_words - ecorrect;
			ecorrect=correct_words;

			Each_line.push_back(wrong_words_each_line);
			Each_line.push_back(correct_words_each_line);
			Each_line.push_back(wpm);
			
			
		}
		inout.close();
		try
		{
			if(FAIL==showResults())
			{
				throw FAIL;
			}
		}
		catch(STATUS x)
                {
                       cout<<"exception caught in showResults() "<<endl;
                       exit(FAIL);
                }
		cout<<"\n Press 1 to retry\npress any key to exit"<<endl;
			scanf("%c",&choice);
			__fpurge(stdin);
			if(choice == '1')
			{
				setZero();
				goto B;
			}
			else
			{
				return FAIL;
			}
		
}		
