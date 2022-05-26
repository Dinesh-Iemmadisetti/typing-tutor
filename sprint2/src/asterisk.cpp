/**********************************************************************************
**
** FILENAME : asterisk.cpp
**
** DESCRIPTIION : It will convert and mask the Users input into asterisk(*).
**
**    CREATED BY                   DATE
**---------------------------------------------------------
** 	Team-1          	24-05-2022
**
********************************************************************************/
#include <termios.h>
#include <unistd.h>
#include<stdio_ext.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

/*********************************************************************
**
** Function NAME: getch() 
**
** DESCRIPTION  : Converting the input characters using terminal commands from termios header .
**
** RETURNS : int
**
**********************************************************************/
int getch()
{
    int ch;
    struct termios t_old, t_new;
    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
	__fpurge(stdin);
    return ch;
}
/*********************************************************************
**
** Function NAME: getch() 
**
** DESCRIPTION  : Storing password into string and changing those into asterisk (*).
**
** RETURNS : int
**
**********************************************************************/
string getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  string password;
  unsigned char ch=0;

  cout <<prompt;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

