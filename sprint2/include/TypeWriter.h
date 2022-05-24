/******************************
filename:TypeWriter.h
description:This class Typewriter declares private ,public variales and methods to calculate accuracy of correct and wrong words
created by            date:
    Team-1            24-05-2022
********************************/

#ifndef CLASS_TYPEWRITER_HEADER
#define CLASS_TYPEWRITER_HEADER
#include<iostream>
#include<string>
using namespace std;
/***********************class**********************/
class TypeWriter
{
	int correct_words;                                     //stores the correct words
	int wrong_words;                                       //stores the wrong words
	int correct_letters;                                   //stores the correct letters
	int wrong_letters;                                     //stores the wrong letters
	int wordsAndLettersCompare(string str1,string str2);   //this function compares the words and letters
	int setZero();                                         //this function sets the zero to all words ad letters
	fstream selectDifficulty();                            //this function reads the text files
  public:
	TypeWriter();                                         //constructor
    	 int typeCheckReport();                               //this function displays the typing report
};
#endif
