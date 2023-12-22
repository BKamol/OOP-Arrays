#pragma once
#include "RationalArray.h"
#include "RationalNumber.h"

using namespace std;

class RationalMatrix
{
private:
	int size;
	RationalArray* mat;

public:
	RationalMatrix();
	RationalMatrix(int _size);
	RationalMatrix(const RationalMatrix& other);

	RationalMatrix& operator=(const RationalMatrix& other);
	bool operator==(const RationalMatrix& other);

	RationalArray& operator[](int i) const { return mat[i]; }
	int get_size() const { return size; }
	RationalArray* get_mat() const { return mat; }
	RationalNumber sled() const;

	RationalMatrix operator+(const RationalMatrix& other) const;
	RationalMatrix operator*(const RationalMatrix& other) const;

	friend istream& operator>>(std::istream& in, RationalMatrix& matr);
	friend ostream& operator<<(std::ostream& out, const RationalMatrix& matr);

	~RationalMatrix() { delete[] mat; }
};