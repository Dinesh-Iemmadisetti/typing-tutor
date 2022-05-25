#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string>
#include<memory>
#include<stdexcept>
#include"TypeWriter.h"
enum STATUS{FAIL,SUCCESS};
using namespace std;

TypeWriter::TypeWriter()
{
	correct_words=0;
	wrong_words=0;
        correct_letters=0;
        wrong_letters=0;
}


int TypeWriter :: wordsAndLettersCompare(string tok1 , string tok)
{

	if(tok1.length()<tok.length())
	{
		for(unsigned int i=0;i<tok1.length();i++)
		{
			if(tok1[i]==tok[i])
			{
				++correct_letters;
		//		cout<<"correct_letters : "<<correct_letters<<endl;
			}
			else
			{
			++wrong_letters;
		//	cout<<"wrong_letters : "<<wrong_letters<<endl;
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
		//								cout<<"correct_letters : "<<correct_letters<<endl;
				}
				else
				{
					++wrong_letters;
//						cout<<"wrong_letters : "<<wrong_letters<<endl;
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

int TypeWriter :: setZero()
{
	wrong_words=0;
	correct_words=0;
	wrong_letters=0;
	correct_letters=0;
	return SUCCESS;
}
/*
fstream TypeWriter :: selectDifficulty()
{
	int choice=0;
	A:cout<<"Select Difficulty Levels"<<endl;
	cout<<"1.Easy"<<endl;
	cout<<"2.Moderate"<<endl;
	cout<<"3.Difficult"<<endl;
	cin>>choice;
	__fpurge(stdin);
	if(choice==1)
	{
		fstream select;
		select.open("./../text/easy.txt",ios::in|ios::out);
                return select;
        }
        else if(choice==2)
        {
               fstream select;
               select.open("./../text/medium.txt",ios::in|ios::out);
               return select;
        }
        else if(choice==3)
        {
              fstream select;
              select.open("./../text/hard.txt",ios::in|ios::out);
              return select;
        }
	else
		goto A;
	

}*/
fstream TypeWriter :: selectDifficulty()
{
	int choice=0;
	A:cout<<"Select Difficulty Levels"<<endl;
	cout<<"1.Easy"<<endl;
	cout<<"2.Moderate"<<endl;
	cout<<"3.Difficult"<<endl;
	cin>>choice;
	__fpurge(stdin);
	if(choice==1)
	{
		fstream select;
		try
		{
			select.open("./../text/easy.txt",ios::in|ios::out);
			if(select.is_open())
			   {
                		return select;
			   }
			   else
			   	throw 1;
			   
    		 }
		catch(int x)
		   {
				cout<<"easy.txt file not found"<<endl;
				exit(0);
		   }
	}
        else if(choice==2)
        {
               fstream select;
		try
		{
               		select.open("./../text/medium.txt",ios::in|ios::out);
			if(select.is_open())
			{
               			return select;
			}
			else
				throw 1;
		}
		catch(int x)
		{
			cout<<"medium.txt file not found"<<endl;
			exit(0);
		}
        }
        else if(choice==3)
        {
              fstream select;
		try
		{
             		 select.open("./../text/hard.txt",ios::in|ios::out);
			if(select.is_open())
			{
              			return select;
			}
			else
				throw 1;
		}
		catch(int x)
		{
			cout<<"hard.txt file not found"<<endl;
			exit(0);
		}
		
        }
	else
		goto A;
	

}

int TypeWriter::typeCheckReport()
{
	B:
	int choice=0;
	char line[100];
	char write[100];
	time_t start=0,end=0,time_per_line=0,total=0;
	int c_word=0;
	int c_line=0;
	int wpm=0;
	int l_num=0;
	int w_line=0;
	string s1;
	fstream inout;
	inout=selectDifficulty();
//	inout.open("./../text/test.txt",ios::in|ios::out);

	if(inout.is_open())
	{
		while(!inout.eof())
		{
			
			inout.getline(line,100);
			//show the lines to write
			__fpurge(stdin);

			if(inout.eof())
				break;

			++l_num;
			cout<<"Line no "<<l_num<<" :"<<line<<endl;
			start=time(NULL);
			cout<<"Type here :";
			fgets(write,100,stdin);
			write[strlen(write)-1]='\0';
			string s2(write);
//			cout<<"line chech : "<<s2.compare(line)<<endl;
			if(s2.compare(line)==0)
			{
				c_line++;
			}
			else
			{
				w_line++;
			}
			string l1=line;
		//	cout<<"first : "<<l1<<endl;
			int pos=0;
			int pos1=0;
			string tok1;
			string tok;
			while(1)
			{
		//		cout<<"l1 : "<<l1<<endl;
				//divide the string into token using space(" ")
				pos=l1.find(" ");
	//			cout<<"pos"<<pos<<endl;
				if(pos!=-1)
				{
					tok=l1.substr(0,pos);
		//			cout<<"tok : "<<tok<<endl;
		//			cout<<"************\n";
					l1.erase(0,pos+1);
		//			cout<<"s2 : "<<s2<<endl;
					A:pos1=s2.find(" ");
		//			cout<<"pos1 "<<pos1<<endl;
					if(pos1!=-1)
					{
						tok1=s2.substr(0,pos1);
						if(tok1.empty())
						{
						s2.erase(0,pos1+1);
						goto A;
						}
		//				cout<<"tok1 : "<<tok1<<endl;
						s2.erase(0,pos1+1);
						if(tok.compare(tok1)==0)
						{
							correct_words++;
							c_word++;
							correct_letters += tok.length();
		//					cout<<"Correct : "<<correct_words<<endl;
						}
						else
						{
							try
							{
								if(SUCCESS!=wordsAndLettersCompare(tok1 , tok))
								{
										throw 1;	
								}
							}
							catch(int x)
							{
								if(x==1)
								{
									cout<<"Exception Occured"<<endl;
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
		//						cout<<"Correct : "<<correct_words<<endl;
							}
							else
							{
								
								try
								{
									if(SUCCESS!=wordsAndLettersCompare(s2 , tok))
									{
											throw 1;		
									}
								}
								catch(int x)
								{
									if(x==1)
									{
										cout<<"Exception Occured"<<endl;
									}

								}
							
							}
							s2.erase();
						}
					//	wrong_letters+=(int) tok.length();
					
						else if(s2.empty())
						{
		//					cout<<"hii"<<endl;
							wrong_words++;
							wrong_letters+=tok.length();
						}
					}
				
						
				}
				else 	
				{
	//				cout<<"l1 : "<<l1<<endl;
	//				cout<<"s2 : "<<s2<<endl;
					if(l1.compare(s2)==0)
					{
						correct_words++;
						c_word++;
						correct_letters += l1.length();
	//					cout<<"Correct : "<<correct_words<<endl;
					}
					else 
					{
						if(s2.length()!=0)
						{
						
							try
							{
								if(SUCCESS!=wordsAndLettersCompare( s2 , l1))
								{
										throw 1;	
								}
							}
							catch(int x)
							{
								if(x==1)
								{
									cout<<"Exception Occured"<<endl;
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
	//		cout<<strlen(write)<<endl;
	//		cout<<endl<<write<<endl;
	//		cout<<"correct_words words :"<<correct_words<<endl;
	//		cout<<"wrong_words words :"<<wrong_words<<endl;
	//		cout<<"wrong_words lines :"<<w_line<<endl;
	//		cout<<"correct_words line :"<<c_line<<endl;
	//		cout<<"wrong_words letters :"<<wrong_letters<<endl;
	//		cout<<"correct_words letters:"<<correct_letters<<endl;
	//		time_per_line=end-start;
	//		cout<<"no of words\n"<<count<<endl;
			
			try
			{
				if(time_per_line==0)
					throw time_per_line;
				else
					wpm=((c_word)*60)/time_per_line;
	
			}
			catch(long int g)
			{
				cout<<"divide by zero error"<<endl;
				time_per_line=1;
				wpm=(c_word * 60)/1;
			}

			cout<<"\nWords Per Minute for the line :"<<wpm<<endl;
			cout<<"\n*************************************"<<endl;
			c_word=0;
			total+=time_per_line;
//			cout<<"T3 : "<<time_per_line<<endl;
//			cout<<"T4 : "<<total<<endl;
		}
		inout.close();
	//	cout<<"Total lines \n"<<w_line + c_line<<endl;
		cout<<"\n\t\tResults\n\t\t_______\n"<<endl;
		cout<<"Correct words  :"<<correct_words<<endl;
		cout<<"Wrong words    :"<<wrong_words<<endl;
//		cout<<"Wrong lines    :"<<w_line<<endl;
//		cout<<"Correct line   :"<<c_line<<endl;
		cout<<"Wrong letters of entire text file                      :"<<wrong_letters<<endl;
		cout<<"correct letters of entire text file                    :"<<correct_letters<<endl;
		cout<<"\nAccuracy of Wrong letters for the entire Text file   : "<<(wrong_letters*100)/(wrong_letters + correct_letters)<<endl;
		cout<<"\nAccuracy of correct letters for the entire Text file : "<<(100-(wrong_letters*100)/(wrong_letters + correct_letters))<<endl;
		try
		{
			if(correct_words==0)
				throw correct_words;
			else
				cout<<"\nWords Per Minutes for the entire Text file : "<<(60/(total/(correct_words)))<<endl;
		}
		catch(int x)
		{
			cout<<"\nNo correct_words words are written\n";
			cout<<"\ndivide by Zero exception\n";
		}
		cout<<"\npress 1 to retry\npress any key to exit"<<endl;
	//	cin>>choice;
		scanf("%d",&choice);
		__fpurge(stdin);
		if(choice==1)
		{
			setZero();
			goto B;
		}
		else
		{
			return FAIL;
		}
			
		cout<<"\n";
		return SUCCESS;
			
	}
	else
	{
		cout<<"text.txt file not found"<<endl;
		return FAIL;
	}
}		
