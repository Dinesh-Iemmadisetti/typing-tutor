/******************************
filename:Password.h
description:This file Password.h declares private methods to get the user password
created by            date:
    Team-1            24-05-2022
********************************/
#ifndef __PASSWORD_HEARDER__

#define __PASSWORD_HEARDER__


#include<string>
using namespace std;

int getch();                                                      //this function checks the password
string getpass(const char *prompt , bool show_asterisk=true);    //this function validates the password

#endif
