//List.cpp

#include "List.h"

bool List::is_empty() {
	if (!top) {
		return true;
	}
	return false;
}

void List::add(string& name) {
	node* p = new node;
	p->name = name;
	p->value = "";
	if (is_empty()) {
		top = p;
		p->next = nullptr;
	}
	else {
		p->next = top;
		top = p;
	}
}

node* List::find(const string& name) {
	for (node* i = top; i != nullptr; i = i->next) {
		if (i->name == name) {
			return i;
		}
	}
	return nullptr;
}

void List::show() {
	for (node* i = top; i != nullptr; i = i->next) {
		cout << i->name << "\t" << i->value << "\n";
	}
}

List::List() {
	top = nullptr;
}

node &node::operator>(const string& p) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t;
		if (value[i] == '1' && p[i] == '0') {
			t = 0;
		} else {
			t = 1;
		}
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node &node::operator>(const node& p) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t;
		if (value[i] == '1' && p.value[i] == '0') {
			t = 0;
		}
		else {
			t = 1;
		}
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node& node::operator*(const string& p) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t;
		if (value[i] == p[i] && value[i] == '0') {
			t = 0;
		}
		else {
			t = 1;
		}
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node& node::operator*(const node& p) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t;
		if (value[i] == p.value[i] && value[i] == '0') {
			t = 0;
		}
		else {
			t = 1;
		}
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}
node& node::operator+(const string& s){
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t = ((value[i] - '0') + (s[i] - '0')) % 2;
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node& node::operator+(const node& p) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t = ((value[i] - '0') + (p.value[i] - '0')) % 2;
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node& node::operator=(const string& s) {
	value = s;
	return *this;
}

node& node::operator=(const node& p) {
	value = p.value;
	return *this;
}

node& node::operator|(const string& s) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t = (value[i] | s[i])%2;
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node& node::operator|(const node& p) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t = (value[i] | p.value[i])%2;
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node& node::operator&(const string& s) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t = (value[i] & s[i])%2;
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}

node& node::operator&(const node& p) {
	node* tmp = new node;
	for (int i = 0; i < value.size(); ++i) {
		int t = (value[i] & p.value[i])%2;
		char s = t + '0';
		tmp->value += s;
	}
	return *tmp;
}
node::node() {
	next = nullptr;
}