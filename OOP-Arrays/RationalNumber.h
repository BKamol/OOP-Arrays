#pragma once
#include <iostream>

using namespace std;

class RationalNumber
{
private:
	int num;
	int den;

	int const NOD();
	void reduce();

public:
	RationalNumber();
	RationalNumber(int _num, int _den);
	RationalNumber(const RationalNumber& x);

	void set(int num, int den);
	int get_num() { return num; };
	int get_den() { return den; };

	bool operator==(const RationalNumber& other);
	RationalNumber operator+(const RationalNumber& other);
	RationalNumber operator*(const RationalNumber& other);
	RationalNumber operator*(int n);
	RationalNumber& operator=(const RationalNumber& other);
	RationalNumber operator++();
	RationalNumber operator++(int);

	friend void operator+=(RationalNumber&, const RationalNumber& other);
	friend istream& operator>>(istream& in, RationalNumber& rn);
	friend ostream& operator<<(ostream& out, RationalNumber& rn);

};