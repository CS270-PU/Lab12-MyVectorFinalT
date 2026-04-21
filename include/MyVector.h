#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

class MyVector {
  public:
    static const size_t DEFAULT_CAPACITY = 10;
    static const size_t EXPAND_AMOUNT = 5;

    MyVector (size_t capacity = MyVector::DEFAULT_CAPACITY);
    MyVector (const MyVector &rcVector);
    ~MyVector ();
    
    size_t capacity () const;
    size_t size () const;
    void push_back (int value);
    int& at (size_t index);
    void clear ();

    MyVector& operator= (const MyVector &rcVector);

  private:
    size_t mCapacity;
    size_t mSize;
    int *mpData;
};

#endif