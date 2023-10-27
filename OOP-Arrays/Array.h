#pragma once
#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
	int size;
	T* arr;

public:
	Array()
	{
		size = 0;
		arr = NULL;
	}

	Array(int _size)
	{
		size = _size;
		arr = new T[size];
	}

	Array(const Array& a)
	{
		size = a.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = a.arr[i];
	}

	Array(Array&& moved)
	{
		size = moved.size;
		arr = moved.arr;
		moved.arr = NULL;
	}

	Array<T>& operator=(const Array& other)
	{
		if (this == &other) return *this;
		if (arr != NULL) delete[] arr;
		arr = new T[other.size];
		for (int i = 0; i < other.size; i++)
			arr[i] = other.arr[i];
		return *this;
	}

	Array<T>& operator[](int index)
	{
		return arr[index];
	}

	Array<T> operator+(const Array& other)
	{
		Array<T> result(size);
		for (int i = 0; i < size; i++)
			result.arr[i] = arr[i] + other.arr[i];

		return result;
	}

	T operator*(const Array& other)
	{
		T result = other.arr[0] * arr[0];
		for (int i = 1; i < size; i++)
			result += other.arr[i] * arr[i];

		return result;
	}

	bool operator==(const Array& other)
	{
		if (size != other.size) return false;
		for (int i = 0; i < size; i++)
			if (arr[i] != other.arr[i]) return false;

		return true;
	}

	~Array()
	{
		delete[] arr;
	}

	friend istream& operator>>(istream& in, Array<T>& a)
	{
		cout << "Input " << a.size << " elements of array: " << endl;
		for (int i = 0; i < a.size; i++)
			in >> a.arr[i];

		return in;
	}

	friend ostream& operator<<(ostream& out, const Array<T>& a)
	{
		out << "( ";
		for (int i = 0; i < a.size; i++)
			out << a.arr[i] << ' ';
		out << ")" << endl;
		return out;
	}
};





