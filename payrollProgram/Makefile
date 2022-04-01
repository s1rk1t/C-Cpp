#makefile for payroll project

X = g++
XX = -std=c++11

p2: main.o payroll.o employee.o payrecord.o operator.o
	$(X) $(XX) -o p2 main.o payroll.o employee.o payrecord.o operator.o
main.o: main.cpp payroll.h
	$(X) $(XX) -c main.cpp
payroll.o: payroll.cpp employee.h payrecord.h operator.h payroll.h
	$(X) $(XX) -c payroll.cpp
employee.o: employee.cpp employee.h
	$(X) $(XX) -c employee.cpp
payrecord.o: payrecord.cpp payrecord.h
	$(X) $(XX) -c payrecord.cpp
operator.o: operator.cpp employee.h payrecord.h operator.h
	$(X) $(XX) -c operator.cpp

clean: rm *o p2

