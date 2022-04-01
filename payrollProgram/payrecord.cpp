#include"payrecord.h"

Payrecord::Payrecord(double g, double t, double n){
setGross(g);
setTax(t);
setNet(n);
}

Payrecord::Payrecord(){}

void Payrecord::setGross(double g){
this->gross = g;
}

void Payrecord::setTax(double t){
this->tax = t;
}

void Payrecord::setNet(double n){
this->net = n;
}

double Payrecord::getGross() const {
return this->gross;
}

double Payrecord::getTax() const {
return this->tax;
}

double Payrecord::getNet() const{
return this->net;
}
