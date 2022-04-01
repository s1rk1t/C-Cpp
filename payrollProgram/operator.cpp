#include"operator.h"
#include"employee.h"
#include"payrecord.h"

#include<iostream>
#include<fstream>
#include<ostream>
#include<cstring>
#include<iomanip>
using namespace std;

istream & operator >> (istream & in, Employee & e){

char name[80];

string tempName;

double hours;
double wage;

if(!(in >> tempName)) return in;
if(!(in >> hours)) return in;
if(!(in >> wage)) return in;

strcpy(name, tempName.c_str());

e.setName(name);
e.setWage(wage);
e.setHours(hours);

return in;

}

Employee & operator >> (Employee & e, Payrecord & p){


p.setGross(e.getHours()*e.getWage());
p.setTax(e.getHours()*e.getWage()*.15);
p.setNet(e.getHours()*e.getWage()-(e.getHours()*e.getWage()*.15));
return e;
}


ostream & operator << (ostream & os, const Employee & e){
 os << e.getName() << " worked " << fixed << setprecision(2) << e.getHours()
<< " hours at $" << fixed << setprecision(2) << e.getWage() << " per hour" << endl;

return os;
}

ostream & operator << (ostream & os, Payrecord & p){

os << "Gross:	$  " << fixed << setprecision(2) <<  p.getGross() <<"\n"
   << "Taxes:	$  " << fixed << setprecision(2) <<  p.getTax() << "\n"
   << "Net:	$  " << fixed << setprecision(2) <<  p.getNet() << endl;
 

return os;

}
