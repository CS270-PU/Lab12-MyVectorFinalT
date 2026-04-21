#include "MyVector.h"

// constructor
MyVector::MyVector(size_t capacity) {
}

// copy constructor
MyVector::MyVector(const MyVector &rcVector) {
}

// destructor
MyVector::~MyVector() {
}

// capacity
size_t MyVector::capacity() const {
    return 0;
}

// size
size_t MyVector::size() const {
    return 0;
}

// push_back
void MyVector::push_back(int value) {
}

// at
int& MyVector::at(size_t index) {
    return mpData[0];
}

// clear
void MyVector::clear() {
}

// assignment operator
MyVector& MyVector::operator=(const MyVector &rcVector) {
    return *this;
}