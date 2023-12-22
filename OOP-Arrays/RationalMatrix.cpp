#include "RationalMatrix.h"

RationalMatrix::RationalMatrix()
{
	size = 0;
	mat = NULL;
}

RationalMatrix::RationalMatrix(int _size)
{
	size = _size;
	mat = new RationalArray[size];
	for (int i = 0; i < size; i++)
	{
		mat[i] = RationalArray(size);
	}
}

RationalMatrix::RationalMatrix(const RationalMatrix& other)
{
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		mat[i] = other.mat[i];
	}
}

RationalMatrix& RationalMatrix::operator=(const RationalMatrix& other)
{
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		mat[i] = other.mat[i];
	}
	return *this;
}

bool RationalMatrix::operator==(const RationalMatrix& other)
{
	if (size != other.size) return false;

	for (int i = 0; i < size; i++)
	{
		if (!(mat[i] == other.mat[i])) return false;
	}
	return true;
}

RationalNumber RationalMatrix::sled() const
{
	RationalNumber result(0, 1);
	for (int i = 0; i < size; i++)
	{
		result += mat[i][i];
	}

	return result;
}

RationalMatrix RationalMatrix::operator+(const RationalMatrix& other) const
{
	RationalMatrix result(size);

	for (int i = 0; i < size; i++)
	{
		result[i] = other.mat[i] + mat[i];
	}
	return result;
}

RationalMatrix RationalMatrix::operator*(const RationalMatrix& other) const
{
	RationalMatrix result(size);
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			result[i] += other[j] * mat[i][j];
		}
	}
	return result;
}

istream& operator>>(std::istream& in, RationalMatrix& matr)
{
	for (int i = 0; i < matr.size; i++)
	{
		in >> matr[i];
	}
	return in;
}

ostream& operator<<(std::ostream& out, const RationalMatrix& matr)
{
	out << '[' << endl;
	for (int i = 0; i < matr.size; i++)
	{
		out << matr[i];
	}
	out << ']' << endl;
	return out;
}

