#pragma once
#include <iostream>

#include <string>

using namespace std;


class Person {

public:
	Person(string name, int amount) : name(name), amount(amount) {}
	bool operator >(const Person& g)const;
	bool operator ==(const Person& g)const;
	bool operator >=(const Person& g)const;
	bool operator <(const Person& g)const;
	bool operator <=(const Person& g)const;
	bool operator !=(const Person& g)const;
	bool operator >(int amt);
	bool operator ==(int amt);
	bool operator >=(int amt);
	bool operator <(int amt);
	bool operator <=(int amt);
	bool operator !=(int amt);
	friend bool operator >(int amt, const Person& g);
	friend bool operator ==(int amt, const Person& g);
	friend bool operator >=(int amt, const Person& g);
	friend bool operator <(int amt, const Person& g);
	friend bool operator <=(int amt, const Person& g);
	friend bool operator !=(int amt, const Person& g);
	int getAmount() const;
	friend ostream& operator <<(ostream& out, const Person& g);

private:
	string name;
	int amount;

};


bool Person::operator >(const Person& g)const {
	return amount > g.amount;
}

bool Person::operator ==(const Person& g)const {
	return amount == g.amount;
}

bool Person::operator >=(const Person& g)const {
	return amount >= g.amount;
}

bool Person::operator <(const Person& g)const {
	return amount < g.amount;
}

bool Person::operator <=(const Person& g)const {
	return amount <= g.amount;
}

bool Person::operator !=(const Person& g)const {
	return amount != g.amount;
}



bool Person::operator >(int amt) {
	return amount > amt;
}

bool Person::operator ==(int amt) {
	return amount == amt;
}

bool Person::operator >=(int amt) {
	return amount >= amt;
}

bool Person::operator <(int amt) {
	return amount < amt;
}

bool Person::operator <=(int amt) {
	return amount <= amt;
}

bool Person::operator !=(int amt) {
	return amount != amt;
}


bool operator >(int amt, const Person& g) {
	return amt > g.amount;
}

bool operator ==(int amt, const Person& g) {
	return amt == g.amount;
}

bool operator >=(int amt, const Person& g) {
	return amt >= g.amount;
}

bool operator <(int amt, const Person& g) {
	return amt < g.amount;
}

bool operator <=(int amt, const Person& g) {
	return amt <= g.amount;
}

bool operator !=(int amt, const Person& g) {
	return amt != g.amount;
}


int Person::getAmount() const {
	return amount;
}

ostream& operator <<(ostream& out, const Person& g) {
	out << g.name << ": " << g.amount;
	return out;
}