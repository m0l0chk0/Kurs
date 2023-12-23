//List.h
#ifndef KURS_LIST_H
#define KURS_LIST_H
#include <string>
#include <iostream>
using namespace std;

struct node {
	string name, value;
	node* next;
	node();
	node& operator= (const node& p);
	node& operator= (const string& s);
	node& operator+ (const node& p);
	node& operator+ (const string& s);
	node& operator| (const node& p);
	node& operator| (const string& s);
	node& operator& (const node& p);
	node& operator& (const string& s);
	node& operator* (const node& p);
	node& operator* (const string& s);
	node& operator> (const node& p);
	node& operator> (const string& s);

};

class List {
private:
	node* top;
public:
	List();
	bool is_empty();
	void add(string& name);
	node* find(const string& name);
	void show();
};
#endif // !KURS_LIST_H
