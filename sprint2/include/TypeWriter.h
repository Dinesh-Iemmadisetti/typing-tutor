#ifndef CLASS_TYPEWRITER_HEADER
#define CLASS_TYPEWRITER_HEADER
#include<iostream>
#include<string>
using namespace std;

class TypeWriter
{
	int correct_words;
	int wrong_words;
	int correct_letters;
	int wrong_letters;
	int wordsAndLettersCompare(string str1,string str2);
	int setZero();
	fstream selectDifficulty();
  public:
	TypeWriter(); 
    	 int typeCheckReport();
};
#endif
