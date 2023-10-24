#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class IntArray
{
private:
	int size;
	int* arr;
public:
	IntArray();

	IntArray(const int* a, int n);

	IntArray(const IntArray& other);

	IntArray(int n);

	~IntArray();

	int get_size() { return size; }

	IntArray& operator=(const IntArray& other);
	int operator*(const IntArray& other) const;
	int& operator[](int n);
	bool operator==(const IntArray& other);
	IntArray operator+(const IntArray& other);


	friend ostream& operator<<(ostream& out, const IntArray& a);
};
istream& operator>>(istream& in, IntArray& a);
