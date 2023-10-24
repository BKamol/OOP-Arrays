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
	RationalArray(int);
	RationalArray(const RationalArray& other);
	RationalArray(RationalArray&& moved) noexcept;

	RationalArray& operator=(const RationalArray& other);
	RationalNumber& operator[](int index);
	bool operator==(const RationalArray& other);
	RationalNumber operator*(const RationalArray& other);
	RationalArray operator+(const RationalArray& other);

	friend istream& operator>>(istream&, RationalArray& rn);
	friend ostream& operator<<(ostream&, RationalArray& rn);

	~RationalArray();
};