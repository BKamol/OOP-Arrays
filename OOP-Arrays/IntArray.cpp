#include "IntArray.h"
#include <iostream>
#include <fstream>

using namespace std;

IntArray::IntArray()
{
	size = 0;
	arr = NULL;
}

IntArray::IntArray(const int* a, int n)
{
	size = n;
	arr = new int[size];
	for (int i = 0; i < n; i++) 
	{
		arr[i] = a[i];
	}
}

IntArray::IntArray(int n)
{
	size = n;
	arr = new int[n];
}

IntArray::IntArray(const IntArray& other) 
{
	size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; i++) 
	{
		arr[i] = other.arr[i];
	}
}

IntArray::~IntArray()
{
	delete[] arr;
}

IntArray& IntArray::operator=(const IntArray& other)
{
	if (&other == this) return *this;
	size = other.size;
	if (arr != NULL) delete[] arr;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];

	return *this;
}

int IntArray::operator*(const IntArray& other) const
{
	int result = 0;
	for (int i = 0; i < size; i++) 
	{
		result += arr[i] * other.arr[i];
	}
	return result;
}

int& IntArray::operator[](int n) 
{
	return arr[n];
}

bool IntArray::operator==(const IntArray& other)
{
	if (size != other.size) return false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != other.arr[i]) return false;
	}
	return true;
}

IntArray IntArray::operator+(const IntArray& other)
{
	IntArray result(size);
	for (int i = 0; i < size; i++)
	{
		result.arr[i] = arr[i] + other.arr[i];
	}
	return result;
}

istream& operator>>(istream& in, IntArray& a)
{
	cout << "Input " << a.get_size() << " integers" << endl;
	for (int i = 0; i < a.get_size(); i++)
	{
		in >> a[i];
	}
	return in;
}

ostream& operator<<(ostream& out,const IntArray& a)
{
	if (a.size == 0) cout << "Empty array" << endl;
	else
	{
		cout << "( ";
		for (int i = 0; i < a.size; i++)
		{
			cout << a.arr[i] << ' ';
		}
		cout << ')' << endl;
	}
	return out;
}