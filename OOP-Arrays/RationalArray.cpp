#include "RationalArray.h"
#include "RationalNumber.h"

RationalArray::RationalArray()
{
	arr = NULL;
	size = 0;
}

RationalArray::RationalArray(int n)
{
	size = n;
	arr = new RationalNumber[size];
}

RationalArray::RationalArray(const RationalArray& other)
{
	size = other.size;
	arr = new RationalNumber[size];
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

RationalArray::RationalArray(RationalArray&& moved) noexcept
{
	arr = moved.arr;
	size = moved.size;
	moved.arr = NULL;
}

RationalArray& RationalArray::operator=(const RationalArray& other)
{
	if (this == &other) return *this;

	if (arr != NULL) delete[] arr;

	size = other.size;
	arr = new RationalNumber[size];

	for (int i = 0; i < size; i++) 
	{
		arr[i] = other.arr[i];
	}

	return *this;
}

RationalNumber& RationalArray::operator[](int index)
{
	return arr[index];
}

bool RationalArray::operator==(const RationalArray& other)
{
	if (size != other.size) return false;
	for (int i = 0; i < size; i++)
	{
		if (!(arr[i] == other.arr[i])) return false;
	}
	return true;
}

RationalNumber RationalArray::operator*(const RationalArray& other)
{
	RationalNumber number;
	for (int i = 0; i < size; i++) 
	{
		number += other.arr[i] * arr[i];
	}
	return number;
}

RationalArray RationalArray::operator+(const RationalArray& other)
{
	RationalArray array2(size);
	for (int i = 0; i < size; i++) 
	{
		array2.arr[i] = other.arr[i] + arr[i];
	}
	return array2;
}

istream& operator>>(istream& in, RationalArray& rn)
{
	cout << "Enter " << rn.size << " rational numbers(pairs of num/den): ";
	for (int i = 0; i < rn.size; i++) {
		in >> rn.arr[i];
	}
	return in;
}

ostream& operator<<(ostream& out, RationalArray& rn)
{
	if (rn.arr == NULL) 
	{
		out << "Array is empty" << endl;
		return out;
	}
	out << "( ";
	for (int i = 0; i < rn.size; i++) 
	{
		out << rn.arr[i] << ' ';
	}
	out << ')' << endl;
	return out;
}

RationalArray::~RationalArray()
{
	delete[] arr;
}