#pragma once
#include <stdio.h>

long long int gcd(long long int a, long long int b);

class My_Float {
	
protected:

	long long int numerator, denominator;

	void normalize() {

		if (denominator == 0) throw "ERROR: ZERO DIVISION";

		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}

		long long int gcd_var = gcd(numerator, denominator);

		numerator /= gcd_var;
		denominator /= gcd_var;
	}

public:
	
	My_Float(int num)
	{

		numerator = num;
		denominator = 1;

		normalize();
	}

	My_Float(long long int num = 0, long long int denom = 1) {

		numerator = num; denominator = denom;

		normalize();
	
	}

	My_Float(double fl) {

		const long long int precision = 1000000;

		numerator = fl * precision;
		denominator = precision;

		normalize();
	}

	My_Float(const My_Float& other); 

	void print();

	double decimal(); 

	friend My_Float operator+(My_Float, My_Float);

	friend My_Float operator-(My_Float, My_Float);

	friend My_Float operator*(My_Float, My_Float);

	friend My_Float operator/(My_Float, My_Float);

	friend My_Float operator*(My_Float, int);

	friend bool operator>(const My_Float&, const My_Float&);

	friend bool operator<(const My_Float&, const My_Float&);

	friend bool operator>=(const My_Float&, const My_Float&);

	friend bool operator<=(const My_Float&, const My_Float&);

	friend bool operator==(const My_Float&, const My_Float&);

	friend bool operator!=(const My_Float&, const My_Float&);
};