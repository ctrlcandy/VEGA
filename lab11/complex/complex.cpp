#include <iostream>

#include "complex.h"

Complex add(Complex a, Complex b)
{
	Complex add;
	add.x = a.x + b.x;
	add.y = a.y + b.y;

	return add;
}

Complex mul(Complex a, Complex b)
{
	Complex mul;
	mul.x = a.x * b.x - a.y * b.y;
	mul.y = a.x * b.y + b.x * a.y;

	return mul;
}

Complex div(Complex a, Complex b)
{
	Complex div;
	div.x = (a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y);
	div.y = (a.y * b.x - a.x * b.y) / (b.x * b.x + b.y * b.y);

	return div;
}

float mod(Complex a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

float arg(Complex a)
{
	return tan(a.y / a.x);
}

Complex conjugate(Complex a)
{
	Complex complex;
	complex.x = a.x;
	complex.y = - a.y;

	return complex;
}

void printAlg(Complex a)
{
	std::cout << a.x << " + i" << a.y << std::endl;
}

void printTrig(Complex a)
{
	std::cout << mod(a) << "(cos" << arg(a) << " + isin" << arg(a) << std::endl;
}
void printExp(Complex a)
{
	std::cout << mod(a) << "e ^ i" << arg(a) << std::endl;
}