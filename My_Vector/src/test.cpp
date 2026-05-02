#define _CRT_SECURE_NO_WARNINGS
#include <utility>
#include <iostream>
#include <stdlib.h>
#include "vector.h"
#include "my_satur.h"

int main(void) {

	/*
	ƒемонстраци€ работы классов вещественных чисел MySatur
	
	*/

	Vector <MySatur> a(3);
	a[0] = MySatur(22, 7); 
	a[2] = 2340000.23;
	a.print(); printf(" - a\n\n\n");

	Vector <MySatur> b(3);

	b[0] = 22.7;
	b[1] = 3.14;
	b[2] = 2.71;

	b.print(); printf(" - b\n\n\n");

	(a + b).print(); printf(" - a+b\n\n\n");

	(a - b).print(); printf(" - a-b\n\n\n");

	printf("========================\n\n\n");

	Vector <double> c(3);
	c[0] = 3.14;
	c[2] = 234.23;
	c.print(); printf(" - a\n\n\n");

	Vector <double> d(3);

	d[0] = 22.7;
	d[1] = 3.14;
	d[2] = 2.71;

	d.print(); printf(" - b\n\n\n");

	(c + d).print(); printf(" - a+b\n\n\n");

	(c - d).print(); printf(" - a-b\n\n\n");

	printf("========================\n\n\n");
	
	Vector <int> e(3);
	e[0] = 3;
	e[2] = 234;
	e.print(); printf(" - a\n\n\n");

	Vector <int> f(3);

	f[0] = 22;
	f[1] = 3;
	f[2] = 2;

	f.print(); printf(" - b\n\n\n");

	(e + f).print(); printf(" - a+b\n\n\n");

	(e - f).print(); printf(" - a-b\n\n\n");

	printf("========================\n\n\n");

	Vector<Vector<int>> vec(2);

	vec[0] = e;
	vec[1] = f;

	vec.print(); printf(" - vec\n\n\n");

	printf("========================\n\n\n");
	
	Vector<Vector<int>> vec2(2, 2);

	vec2.print(); printf(" - vec2\n\n\n");

	printf("========================\n\n\n");

	vec2.push_back(e);

	vec2.print(); printf(" - vec2\n\n\n");

	printf("========================\n\n\n");

	return 1;
}