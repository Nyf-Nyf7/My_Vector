#pragma once
#include "my_float.h"


constexpr int SATURATED = 100000;
class MySatur :public My_Float {

	bool SatFlag;

	void normalize() {

		if (decimal() > SATURATED) {

			SatFlag = true;

			numerator = 100000;
			denominator = 1;
		}

		else if (decimal() < - SATURATED) {
			SatFlag = true;

			numerator = -100000;
			denominator = 1;

		}

		else SatFlag = false;

	}

public:

	MySatur(long long int num = 0, long long int denom = 1) : My_Float(num, denom) {

		normalize();

	}

	MySatur(int num) {

		numerator = num;
		denominator = 1;

		normalize();

	}

	MySatur(double fl) : My_Float(fl) {

		normalize();

	}

	MySatur(const My_Float& other):My_Float(other) {		
		normalize();
	}

	void print() {
		if (SatFlag) printf("*");
		My_Float::print();
	}

};