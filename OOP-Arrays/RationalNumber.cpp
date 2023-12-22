#include "RationalNumber.h"
#include <iostream>
using namespace std;

int const RationalNumber::NOD()
{
    int a = num;
    int b = den;
    while (a != 0 && b != 0)
        if (abs(a) > abs(b))
            a %= b;
        else
            b %= a;
    return a + b;
}

void RationalNumber::reduce()
{
    int nod = NOD();
    den /= nod;
    num /= nod;
}

RationalNumber::RationalNumber()
{
    num = 0;
    den = 1;
}

RationalNumber::RationalNumber(int _num, int _den)
{
    this->num = _num;
    this->den = _den;
}

RationalNumber::RationalNumber(const RationalNumber& x)
{
    num = x.num;
    den = x.den;
}

void RationalNumber::set(int num, int den)
{
    this->num = num;
    this->den = den;
}

bool RationalNumber::operator==(const RationalNumber& other)
{
    return num == other.num && den == other.den;
}

RationalNumber RationalNumber::operator+(const RationalNumber& other)
{
    RationalNumber temp;
    temp.num = num * other.den + other.num * den;
    temp.den = den * other.den;
    return temp;
}

RationalNumber RationalNumber::operator*(const RationalNumber& other)
{
    RationalNumber temp;
    temp.num = num * other.num;
    temp.den = den * other.den;
    return temp;
}

RationalNumber RationalNumber::operator*(int n)
{
    RationalNumber result(num * n, den);
    return result;
}

RationalNumber& RationalNumber::operator=(const RationalNumber& other)
{
    num = other.num;
    den = other.den;
    return *this;
}

RationalNumber RationalNumber::operator++()
{
    num += den;
    return *this;
}

RationalNumber RationalNumber::operator++(int)
{
    RationalNumber other(*this);
    num += den;
    return other;
}

void operator+=(RationalNumber& a, const RationalNumber& other)
{
    a.num = a.num * other.den + other.num * a.den;
    a.den *= other.den;
}

istream& operator>>(istream& in, RationalNumber& rn)
{
    int a, b;
    in >> a >> b;

    rn.set(a, b);

    return in;
}

ostream& operator<<(ostream& out, RationalNumber& rn)
{
    rn.reduce();
    out << rn.get_num() << "/" << rn.get_den() << ' ';
    return out;
}