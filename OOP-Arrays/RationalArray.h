#pragma once
#include "RationalNumber.h"
#include <iostream>
using namespace std;

class RationalArray
{
private:
	RationalNumber* arr;
	int size;

public:
	RationalArray();
	RationalArray(int n);
	RationalArray(const RationalArray& other);
	RationalArray(RationalArray&& moved) noexcept;

	RationalNumber* get_arr() { return arr; }
	int get_size() { return size; }

	RationalArray& operator=(const RationalArray& other);
	RationalNumber& operator[](int index);
	bool operator==(const RationalArray& other);
	RationalNumber operator*(const RationalArray& other);
	RationalArray operator+(const RationalArray& other);
	RationalArray operator*(RationalNumber rn);

	void operator+=(const RationalArray& other);

	friend istream& operator>>(istream&, RationalArray& rn);
	friend ostream& operator<<(ostream&, RationalArray& rn);

	~RationalArray();
};