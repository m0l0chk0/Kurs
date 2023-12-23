//Compilator.h

#ifndef KURS_COMPILATOR_H
#define KURS_COMPILATOR_H
#include <string>
#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

inline node& operator+ (const string& s1, const string& s2);
inline node& operator| (const string& s1, const string& s2);
inline node& operator& (const string& s1, const string& s2);
inline node& operator* (const string& s1, const string& s2);
inline node& operator> (const string & s1, const string & s2);

class Compilator {
private:
	ifstream in;
	List* vars;
	int i, q;
	string s, var_err;
public:
	Compilator();
	void analyze();
	void print_error();
	void memory();
	void compute();
	void show();
	static bool is_var(string& com);
	~Compilator();

};
#endif // !KURS_COMPILATOR_H

