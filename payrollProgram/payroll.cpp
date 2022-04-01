#include"payroll.h"
#include"operator.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<ostream>
#include"employee.h"
#include"payrecord.h"
#include<string>

using namespace std;

Payroll::Payroll(){
}




void Payroll::readBatch(){

cout<<"Please enter the name of the batch file."<<endl;

string batch;

cin >> batch;

ifstream ifs;
string firstLine;


	try{
	ifs.open(batch);
	}
	catch (std::ifstream::failure e) {
	cout << "File not found!" << endl;
	}


	if(getline(ifs, firstLine)){
	 num_employees = atoi(firstLine.c_str());
	}
	else{
	cout << "File contains improper or no information!" << endl;
	}
	



	
	string nextLine;
	for(int index = 0; index < num_employees; ++index){
	if(getline(ifs, nextLine)){
	stringstream ss;	
	ss << nextLine;
	ss >> employees[index];
	employees[index] >> payrecords[index];
	}
	else{
	cout << "Error instantiating employee and payrecords" <<endl;
}//end batch
}
}

double Payroll::getNet(const Employee & emp){
	 double net = emp.getHours()*emp.getWage()-(emp.getHours()*emp.getWage()*.15);
	return net;
}//getnet

double Payroll::getTax(const Employee & emp){ 
	 double taxes = ((emp.getWage())*(emp.getHours()))*(.15);
	return taxes; 
}//gettax

double Payroll::getGross(const Employee & emp){
	 double gross = emp.getWage()*emp.getHours();
	return gross;
}//getgross

const Employee & Payroll::findHigh() const{
	int index = 0;
	for(int i = 0; i < num_employees; ++i){
	if (employees[i].getWage() > employees[index].getWage())
	index = i;
	}
	return employees[index]; 
}//findhigh


const Employee & Payroll::findLow() const{
	int index = 0;
	for(int i = 0; i < num_employees; ++i){
	if (employees[i].getWage() < employees[index].getWage())
	index = i;
	}
	return employees[index];
}//findlow


void Payroll::generateChecks(){
	if(num_employees != 0){
	cout << "Please enter the name of the file to be written." << endl;
	string filename;
	if(cin >> filename){
	ofstream output(filename);
	for(int i = 0; i < num_employees; ++i){
	output << employees[i] << endl;
	output << payrecords[i] << endl;
	cout << endl;
	}
	}//second if	
	else{
	for(int i = 0; i < num_employees; ++i){
	cout << employees[i] << endl;
	cout << payrecords[i] << endl;
	}
	}//else
	}//first if
	
	else{
	cout << "Error reading in batch file." << endl;
	exit(1);
	}//else
}//genchecks	

void Payroll::generateReports(){
if(num_employees != 0){
string filename;
cout << "Please enter the name of the file to be written." <<endl;

if(cin >> filename)){

ofstream outputFile(filename);

outputFile << "  " << "Report\n" <<endl;
outputFile << "Highest Earning Employee: \n";
outputFile << findHigh(); 
outputFile << "\n" << endl;
outputFile << "Lowest Earning Employee: \n"; 
outputFile << findLow(); 
outputFile << "\n" << endl;
outputFile << "Totals:" <<endl;
outputFile << "Total Gross Pay  $ " << fixed << setprecision(2) << findTotalGross() << endl;
outputFile << "Total Tax	 $ " << fixed << setprecision(2) << findTotalTax() << endl;
outputFile << "Total Net Pay	 $ " << fixed << setprecision(2) << findTotalNet() << endl;
outputFile << "\nAverages:" << endl;
outputFile << "Average Gross Pay $ " << std::setprecision(2) << findAvgGross() << endl;
outputFile << "Average Tax       $ " << std::setprecision(2) << findAvgTax() << endl;
outputFile << "Average Net Pay   $ " << std::setprecision(2) << findAvgNet() << endl;
}
else{
cout << "Error getting filename." << endl;
if(num_employees == 0){
cout << "Error reading in batch file." << endl;
exit(1);
}
}
}//end genreports

const double Payroll::findTotalTax() const{
	double tax;
	
	for(int i = 0 ; i < num_employees ; ++i){
	tax += getTax(employees[i]);
	
	}//for
	const double totalTaxes = tax;
	
	return totalTaxes;
}//findtotaltax

const double Payroll::findTotalGross() const{
	double gross;
	for(int i = 0; i < num_employees ; ++i){
	gross += getGross(employees[i]);
	}
	const double totalGross = gross;
	return totalGross;

}//gettotalgross

const double Payroll::findTotalNet() const{
	
	
	double net;
	for(int i = 0; i < num_employees; ++i){
	net += (getGross(employees[i])-getTax(employees[i]));
	}
	const double totalNet = net;
	return totalNet;
}//findtotalnet

const double Payroll::findAvgGross() const{
	const double avgGross = findTotalGross()/num_employees;
	return avgGross;
}//findavggross

const double Payroll::findAvgTax() const{
	const double avgTax = findTotalTax()/num_employees;
	return avgTax;
}//findAvgtax

const double Payroll::findAvgNet() const{
	double avgNet;

	for(int i = 0; i < num_employees; ++i){
	
	avgNet += getGross(employees[i]) - getTax(employees[i]);
	}
	avgNet = avgNet/num_employees;
	const double finalNet = avgNet;
	return finalNet;
}//findavgnet
	
