// main.cpp
#include "Compilator.h"
using namespace std;

int main()
{
	Compilator compilator;
	compilator.analyze();
	compilator.print_error();
	compilator.memory();
	compilator.compute();
	compilator.show();
	system("pause");
	return 0;
}