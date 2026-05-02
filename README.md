# Custom Vector Implementation in C++

## Description

This student project is a custom implementation of a dynamic array (vector-like container) in C++ using templates.

The goal was to understand low-level memory management, copy/move semantics, and template-based design.

Additionally, the project demonstrates usage of custom numeric types, including a saturation arithmetic class.


## Features

* Template-based container (`Vector<T>`)
* Manual dynamic memory management
* Copy constructor and copy assignment
* Move constructor and move assignment
* Operator overloading (`+`, `-`, `[]`)
* Support for nested vectors (`Vector<Vector<T>>`)
* Custom type support (`MySatur`)
* Basic dynamic resizing (`push_back`)


##  Build & Run

In My_Vector directory:

### Using CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
./app
```

### Using g++

```bash
g++ src/*.cpp -Iincludes -o app.exe
app.exe
```


##  Example

```cpp
Vector<MySatur> a(3);
a[0] = MySatur(22, 7);
a[2] = 234.23;

a.print(); // [3.1429[22/7], 0.0000[0/1], 234.2300[23423/100]]
```


##  Notes

This is an educational project and does not aim to fully replicate `std::vector`.


##  Technologies

* C++
* Visual Studio
* CMake
