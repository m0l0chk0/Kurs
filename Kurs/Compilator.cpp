//Compilator.cpp
#include "Compilator.h"
void Compilator::analyze() {
	in.open("input.txt");
	string c;
	while (!in.eof()) {
		in >> c;
		s += c;
	}
	int q = 0;
	for (i = 0; i < s.size() && q < 20; i++) {
		switch (q) {
		case 0:
		{
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
				q = 1;
			else q = 20;
			break;
		}
		case 1:
		{
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
				q = 2;
			else if (s[i] == ':') q = 4;
			else q = 21;
			break;
		}
		case 2:
		{
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
				q = 3;
			else if (s[i] == ':') q = 4;
			else q = 21;
			break;
		}
		case 3:
		{
			if (s[i] == ':')q = 4;
			else q = 22;
			break;
		}
		case 4:
		{
			if (s[i] == '=')q = 5;
			else q = 23;
			break;
		}
		case 5:
		{
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
				q = 6;
			else if (s[i] >= '0' || s[i] <= '1') q = 9;
			else q = 24;
			break;
		}
		case 6:
		{
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' || s[i] <= '1'))
				q = 7;
			else if (s[i] == '&' || s[i] == '|' || s[i] == '+' || s[i] == '*' || s[i] == '>') q = 5;
			else if (s[i] == ';')q = 0;
			else q = 25;
			break;
		}
		case 7:
		{
			if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' || s[i] <= '1'))
				q = 8;
			else if (s[i] == '&' || s[i] == '|' || s[i] == '+' || s[i] == '*' || s[i] == '>') q = 5;
			else if (s[i] == ';')q = 0;
			else q = 25;
			break;
		}
		case 8:
		{
			if (s[i] == '&' || s[i] == '|' || s[i] == '+' || s[i] == '*' || s[i] == '>') q = 5;
			else if (s[i] == ';')q = 0;
			else q = 26;
			break;
		}
		case 9:
		{
			if (s[i] == '0' || s[i] == '1') q = 11;
			else q = 27;
			break;
		}
		case 10:
		{
			if (s[i] == '0' || s[i] == '1') q = 11;
			else q = 27;
			break;
		}
		case 11:
		{
			if (s[i] == '0' || s[i] == '1') q = 12;
			else q = 27;
			break;
		}
		case 12:
		{
			if (s[i] == '0' || s[i] == '1') q = 13;
			else q = 27;
			break;
		}
		case 13:
		{
			if (s[i] == '0' || s[i] == '1') q = 14;
			else q = 27;
			break;
		}
		case 14:
		{
			if (s[i] == '0' || s[i] == '1') q = 15;
			else q = 27;
			break;
		}
		case 15:
		{
			if (s[i] == '0' || s[i] == '1') q = 8;
			else q = 27;
			break;
		}
		}
	}
	in.close();
}

void Compilator::print_error() 
{
	if (q == 0) cout << "All right!" << endl;
	if (q == 20) cout << "Error! Expected letter at postion" << endl;
	if (q == 21|| q == 1|| q == 2) cout << "Error! Expected letter, number or ':' after '"<<s[i-2]<<"' at position " <<i-2<< endl;
	if (q == 22|| q == 3) cout << "Error! Expected ':' after '" << s[i - 2] << "' at position " << i - 2<< endl;
	if (q == 23 || q == 4) cout << "Error! Expected '=' after '" << s[i - 2] << "' at position " << i - 2 << endl;
	if (q == 24 || q == 5) cout << "Error! Expected letter, '0' or '1' after '" << s[i - 2] << "' at position "<< i - 2 << endl;
	if (q == 25 || q == 7) cout << "Error! Expected letter, number, arithmetic symbol or ';' after '" <<s[i-2]<< "' at position "<< i - 2 << endl;
	if (q == 26 || q == 8) cout << "Error! Expected arithmetic symbol or ';' after '"<< s[i-2]<<"' at position "<<i-2 << endl;
	if (q == 27 || (q >= 9 && q <= 15)) cout << "Error! Expected '0' or '1' after '"<< s[i-2]<<"' at position "<< i - 2 << endl;
	if (q == 29) cout << "Error! Variable " << var_err<<" isn't exist" <<endl;

}

void Compilator::show() {
	if (q == 0) {
		vars->show();
	}
}

bool Compilator::is_var(string& comm) {
	if ((comm[0] >= 'A' && comm[0] <= 'Z') || (comm[0] >= 'a' && comm[0] <= 'z')) {
		return true;
	}
	return false;
}
Compilator::~Compilator() {
	delete vars;
}
void Compilator::compute() {
	if (q == 0) {
		in.open("input.txt");
		string prev, curr;
		in >> prev;
		node* var = nullptr;
		while (!in.eof()) {
			in >> curr;
			if (curr == ":=") {
				var = vars->find(prev);
				string command1, command2, operation;
				in >> command1;
				if (command1[command1.size() - 1] == ';') {
					command1.erase(command1.size() - 1);
					if (is_var(command1)) {
						*var = *vars->find(command1);

					}
					else {
						*var = command1;
					}
				}
				else {
					in >> operation >> command2;
					command2.erase(command2.size() - 1);
					node* var1 = nullptr, * var2 = nullptr;
					if (is_var(command1)) {
						var1 = vars->find(command1);
						if (!var1) {
							q = 29;
							var_err = command1;
							print_error();
							return;
						}
					}
					if (is_var(command2)) {
						var2 = vars->find(command2);
						if (!var2) {
							q = 29;
							var_err = command2;
							print_error();
							return;
						}
					}
					switch (operation[0]) {
					case '+':
						if (var1 && var2) {
							*var = *var1 + *var2;
						}
						else if (var1 && !var2) {
							*var = *var1 + command2;
						}
						else if (!var1 && var2) {
							*var = *var2 + command1;
						}
						else {
							*var = command1 + command2;
						}
						break;
					case '|':
						if (var1 && var2) {
							*var = *var1 | *var2;
						}
						else if (var1 && !var2) {
							*var = *var1 | command2;
						}
						else if (!var1 && var2) {
							*var = *var2 | command1;
						}
						else {
							*var = command1 | command2;
						}
						break;
					case '&':
						if (var1 && var2) {
							*var = *var1 & *var2;
						}
						else if (var1 && !var2) {
							*var = *var1 & command2;
						}
						else if (!var1 && var2) {
							*var = *var2 & command1;
						}
						else {
							*var = command1 & command2;
						}
						break;
					case '*':
						if (var1 && var2) {
							*var = *var1 * *var2;
						}
						else if (var1 && !var2) {
							*var = *var1 * command2;
						}
						else if (!var1 && var2) {
							*var = *var2 * command1;
						}
						else {
							*var = command1 * command2;
						}
						break;
					case '>':
						if (var1 && var2) {
							*var = *var1 > *var2;
						}
						else if (var1 && !var2) {
							*var = *var1 > command2;
						}
						else if (!var1 && var2) {
							*var = *var2 > command1;
						}
						else {
							*var = command1 > command2;
						}
						break;
					}
				}
			}
			prev = curr;
		}

	}
}

void Compilator::memory() {
	in.open("input.txt");
	string curr, prev;
	in >> prev;
	while (!in.eof()) {
		in >> curr;
		if (curr == ":=") {
			if (!vars->find(prev)) {
				vars->add(prev);
			}
		}
		prev = curr;
	}
	in.close();
}
Compilator::Compilator() {
	q = 0;
	i = 0;
	vars = new List;
}

node& operator>(const string& s1, const string& s2) {
	node* tmp = new node;
	for (int i = 0; i < s1.size(); ++i) {
		int t = ((int)s1[i] > (int)s2[i]) % 2;
		tmp->value += (char)(t + '0');
	}
	return *tmp;
}
node& operator+(const string& s1, const string& s2) {
	node* tmp = new node;
	for (int i = 0; i < s1.size(); ++i) {
		int t = ((int)s1[i] + (int)s2[i]) % 2;
		tmp->value += (char)(t + '0');
	}
	return *tmp;
}
node& operator&(const string& s1, const string& s2) {
	node* tmp = new node;
	for (int i = 0; i < s1.size(); ++i) {
		int t = ((int)s1[i] & (int)s2[i]) % 2;
		tmp->value += (char)(t + '0');
	}
	return *tmp;
}
node& operator|(const string& s1, const string& s2) {
	node* tmp = new node;
	for (int i = 0; i < s1.size(); ++i) {
		int t = ((int)s1[i] | (int)s2[i]) % 2;
		tmp->value += (char)(t + '0');
	}
	return *tmp;
}
node& operator*(const string& s1, const string& s2) {
	node* tmp = new node;
	for (int i = 0; i < s1.size(); ++i) {
		int t = ((int)s1[i] * (int)s2[i]) % 2;
		tmp->value += (char)(t + '0');
	}
	return *tmp;
}