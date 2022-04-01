#include"employee.h"
#include<string>
#include<cstring>

Employee::Employee(char * n, double h, double w){
strcpy(name, n);
hours = h;
wage = w;
}

Employee::Employee(){}

void Employee::setName(char n[]){
strcpy(name, n);
}

void Employee::setHours(double h){
hours = h;
}

void Employee::setWage(double w){
wage = w;
}

const char * Employee::getName() const{
return name;
}

double Employee::getHours() const{
return hours;
}

double Employee::getWage() const{
return wage;
}


