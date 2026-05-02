#include <cmath>
#include "my_float.h"


long long int gcd(long long int a, long long int b) {

	a = abs(a);
	b = abs(b);
	long long int t = a;

	while (b != 0) {
		t = a;
		a = b;
		b = t % b;
	}
	return a;

}

double My_Float::decimal(void) {
	return (double)numerator / (double)denominator;
}

void My_Float::print(void){
	printf("%.4f[%lld/%lld]", decimal(), numerator, denominator);
}

My_Float::My_Float(const My_Float& copy) {
	numerator = copy.numerator;
	denominator = copy.denominator;
}

My_Float operator+(My_Float a, My_Float b) {
	if (a.denominator == b.denominator) return My_Float(a.numerator + b.numerator, b.denominator);

	long long int  t_var = 1;

	a.numerator *= b.denominator;
	t_var = a.denominator;
	a.denominator *= b.denominator;

	b.numerator *= t_var;
	b.denominator = a.denominator;
		
	long long int gcd_var = gcd(a.numerator + b.numerator, b.denominator);
	return My_Float( (a.numerator + b.numerator) / gcd_var, b.denominator / gcd_var);
}

My_Float operator-(My_Float a, My_Float b) {
	if (a.denominator == b.denominator) return My_Float(a.numerator - b.numerator, b.denominator);
	else {

		long long int t_var = 1;

		a.numerator *= b.denominator;
		t_var = a.denominator;
		a.denominator *= b.denominator;

		b.numerator *= t_var;
		b.denominator = a.denominator;

		long long int gcd_var = gcd(a.numerator - b.numerator, b.denominator);
		return My_Float((a.numerator - b.numerator) / gcd_var, b.denominator / gcd_var);
	}
}

My_Float operator*(My_Float a, My_Float b) {
	
	long long int gcd_var = gcd(a.numerator * b.numerator, a.denominator * b.denominator);
	return My_Float((a.numerator * b.numerator) / gcd_var, a.denominator * b.denominator / gcd_var);

}

My_Float operator/(My_Float a, My_Float b) {

	My_Float reverse(b.denominator, b.numerator);
	
	long long int gcd_var = gcd(a.numerator * reverse.numerator, a.denominator * reverse.denominator);
	return My_Float((a.numerator * reverse.numerator) / gcd_var, a.denominator * reverse.denominator / gcd_var);
}

My_Float operator*(My_Float a, int b) {

	long long int gcd_var = gcd(a.numerator * b, a.denominator);
	return My_Float((a.numerator * b) / gcd_var, a.denominator / gcd_var);

}

bool operator>(const  My_Float& a, const  My_Float& b) {

	My_Float dif = a - b;

	return dif.numerator > 0;
}

bool operator<(const  My_Float& a, const  My_Float& b) {

	My_Float dif = a - b;

	return dif.numerator < 0;
}

bool operator>=(const  My_Float& a, const  My_Float& b) {

	My_Float dif = a - b;

	return dif.numerator >= 0;
}
bool operator<=(const  My_Float& a, const  My_Float& b) {

	My_Float dif = a - b;

	return dif.numerator <= 0;
}
bool operator==(const  My_Float& a, const  My_Float& b) {

	My_Float dif = a - b;

	return dif.numerator == 0;
}
bool operator!=(const  My_Float& a, const  My_Float& b) {

	My_Float dif = a - b;

	return dif.numerator != 0;
}