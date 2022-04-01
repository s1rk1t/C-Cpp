#ifndef OPERATOR_H
#define OPERATOR_H
#include"employee.h"
#include<sstream>
#include<iostream>
#include<fstream>
#include<ostream>
#include"payrecord.h"

using namespace std;

istream & operator >> (istream & in,  Employee & e);

ostream & operator << (ostream & os, const  Employee & e);

ostream & operator << (ostream & os,  Payrecord & p);

Employee & operator >> (Employee & e, Payrecord & p);
#endif
