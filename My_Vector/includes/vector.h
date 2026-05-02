#pragma once
#include <iostream>
#include <stdlib.h>
#include <new>
#include "my_satur.h"


constexpr int DEFAULT_SZ = 99;

template <typename typeobj> class Vector {

	typeobj* var;
	int sz;

public:
	

	Vector(int s, int r = 0) {
		sz = s;

		if (r == 0) {
			try {
				var = new typeobj[s]();
			}
			catch (std::bad_alloc&) {
				std::cerr << "Vector Size Error\n";
				std::exit(1);
			}
		}

		if (r != 0){
				try {
				var = new typeobj[r];

				for (int i = 0; i < r; i++) {
					var[i] = typeobj(s);
					}
				}
				catch (std::bad_alloc&) {
					std::cerr << "Nested Vector Size Error\n";
					std::exit(1);
				}
		}
	}

	Vector() : Vector(DEFAULT_SZ) {}

	~Vector() { delete[]var; }

	typeobj& operator[](int i) {
		try {
			return var[i];
		}
		catch (const char* err) { printf("Index Error: %s", err); exit(-1); }
	}

	inline typeobj& elem(int i) {
		return var[i];
	}

	inline int size() {
		return sz;
	}

	//конструктор копирования
	Vector(const Vector& other) {

		sz = other.sz;
		var = new typeobj[sz];
		for (int i = 0; i < sz; i++) var[i] = other.var[i];
	}

	
	//конструктор перемещения
	Vector(Vector&& other) noexcept {

		sz = other.sz;
		var = other.var;
		other.var = nullptr;
		other.sz = 0;
	}
	

	//оператор присваивания
	Vector& operator=(const Vector& other) {

		if (this == &other) return *this;

		if (sz == other.sz) {
			for (int i = 0; i < sz; i++) var[i] = other.var[i];
		}
		else{
			delete[] var;
			sz = other.sz;
			var = new typeobj[sz];
			for (int i = 0; i < sz; i++) var[i] = other.var[i];
		}

		return *this;
	}

	//оператор перемещения
	Vector& operator=(Vector&& other) {

		if (this == &other) return *this;

		if (sz == other.sz) {
			for (int i = 0; i < sz; i++) var[i] = other.var[i];
		}
		else {
			delete[] var;
			sz = other.sz;
			var = other.var;
		}
		other.sz = 0; 
		other.var = nullptr;

		return *this;
	}

	void print();


	friend Vector operator+(Vector a, Vector b) {
		if (a.sz >= b.sz) {
			for (int i = 0; i < a.sz; i++) {
				if (i < b.sz) a.elem(i) = a.elem(i) + b.elem(i);
			}
			return a;
		}
		else {
			for (int i = 0; i < a.sz; i++) {
				if (i < b.sz) b.elem(i) = a.elem(i) + b.elem(i);
			}
			return b;
		}
	}

	friend Vector operator-(Vector a, Vector b) {
		if (a.sz >= b.sz) {
			for (int i = 0; i < a.sz; i++) {
				if (i < b.sz) a.elem(i) = a.elem(i) - b.elem(i);
			}
			return a;
		}
		else {
			for (int i = 0; i < a.sz; i++) {
				if (i < b.sz) b.elem(i) = a.elem(i) - b.elem(i);
			}
			return b;
		}
	}

	void push_back(const typeobj& val) {
		
		typeobj* new_data = new typeobj[sz + 1];

		for (int i = 0; i < sz; i++)
			new_data[i] = var[i];

		new_data[sz] = val;

		delete[] var;
		var = new_data;
		sz++;

	}
};


template<typename typeobj>
void print_elem(const typeobj& elem) {
	std::cout << elem;
}


template<typename typeobj>
void print_elem(Vector<typeobj>& vec) {
	vec.print();
}


template<typename typeobj>
void Vector<typeobj>::print() {
	std::cout << "[";
	for (int i = 0; i < sz; i++) {
		print_elem(elem(i));
		if (i < sz - 1) std::cout << ", ";
	}
	std::cout << "]";
}


template<>
void Vector<MySatur>::print() {
	std::cout << "[";
	for (int i = 0; i < sz; i++) {
		elem(i).print();
		if (i < sz - 1) std::cout << ", ";
	}
	std::cout << "]";
}