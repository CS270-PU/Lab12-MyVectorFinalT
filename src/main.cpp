//******************************************************************************
// File name:   main.cpp
// Author:      CS, Pacific University
// Date:        
// Class:       
// Assignment:  
// Purpose:     Driver to test MyVector class
// Hours:       
//******************************************************************************

#include <iostream>
#include "../include/MyVector.h"

int main() {
    MyVector cVector;

    // TODO #1:
    // Implement the constructor MyVector (size_t)

    // TODO #2:
    // Implement size() and capacity()

    std::cout << "Initial size: " << cVector.size() << std::endl;
    std::cout << "Initial capacity: " << cVector.capacity() << std::endl;
//------------------------------------------------------------------------------

    // TODO #3:
    // Implement push_back() (no expand yet)

    cVector.push_back(10);
    cVector.push_back(20);
    cVector.push_back(30);
//------------------------------------------------------------------------------

    // TODO #4:
    // Implement at()

    std::cout << "\nAfter push_back:" << std::endl;
    for (size_t i = 0; i < cVector.size(); i++) {
        std::cout << cVector.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Size: " << cVector.size() << std::endl;
    std::cout << "Capacity: " << cVector.capacity() << std::endl;
//------------------------------------------------------------------------------

    // TODO #5:
    // Test that at() returns a reference

    cVector.at(1) = 99; // changes a value in the vector using at()

    std::cout << "\nAfter modification:" << std::endl;
    for (size_t i = 0; i < cVector.size(); i++) {
        std::cout << cVector.at(i) << " ";
    }
    std::cout << std::endl;
//------------------------------------------------------------------------------

    // TODO #6:
    // Implement clear()

    cVector.clear();

    std::cout << "\nAfter clear:" << std::endl;
    std::cout << "Size: " << cVector.size() << std::endl;
    std::cout << "Capacity: " << cVector.capacity() << std::endl;
//------------------------------------------------------------------------------

    // TODO #7:
    // Implement destructor
    // Then run: make valgrind
    // Confirm there are no memory leaks.

    /*

    Process Completed
    ==81292== 
    ==81292== HEAP SUMMARY:
    ==81292==     in use at exit: 0 bytes in 0 blocks
    ==81292==   total heap usage: 8 allocs, 8 frees, 73,924 bytes allocated
    ==81292== 
    ==81292== All heap blocks were freed -- no leaks are possible
    
    */
//------------------------------------------------------------------------------

    // TODO #8:
    // Implement copy constructor so cCopy gets its own separate array

    cVector.push_back(1);
    cVector.push_back(2);

    MyVector cCopy(cVector);

    std::cout << "\nCopy constructor test:" << std::endl;
    for (size_t i = 0; i < cCopy.size(); i++) {
        std::cout << cCopy.at(i) << " ";
    }
    std::cout << std::endl;

//------------------------------------------------------------------------------

    // TODO #9:
    // Implement assignment operator so cOther gets its own separate array

    MyVector cOther;
    cOther = cVector;

    std::cout << "\nAssignment operator test:" << std::endl;
    for (size_t i = 0; i < cOther.size(); i++) {
        std::cout << cOther.at(i) << " ";
    }
    std::cout << std::endl;

    // Deep copy check
    cVector.at(0) = 999;

    std::cout << "\nAfter modifying original (deep copy check):" << std::endl;
    std::cout << "Original: ";
    for (size_t i = 0; i < cVector.size(); i++) {
        std::cout << cVector.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Copy: ";
    for (size_t i = 0; i < cCopy.size(); i++) {
        std::cout << cCopy.at(i) << " ";
    }
    std::cout << std::endl;
//------------------------------------------------------------------------------

    // TODO #10:
    // Add expand logic to push_back()

    MyVector cSmallVector(2);
    cSmallVector.push_back(5);
    cSmallVector.push_back(6);
    cSmallVector.push_back(7);   // should trigger expand

    std::cout << "\nAfter expand test:" << std::endl;
    for (size_t i = 0; i < cSmallVector.size(); i++) {
        std::cout << cSmallVector.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Size: " << cSmallVector.size() << std::endl;
    std::cout << "Capacity: " << cSmallVector.capacity() << std::endl;

//------------------------------------------------------------------------------

    std::cout << "\nProcess Completed" << std::endl;

    return 0;
}

// Expected Results

/*
vscode ➜ /workspaces/Lab12-MyVectorT (main) $ bin/main.exe 
Initial size: 0
Initial capacity: 10

After push_back:
10 20 30 
Size: 3
Capacity: 10

After modification:
10 99 30 

After clear:
Size: 0
Capacity: 10

Copy constructor test:
1 2 

Assignment operator test:
1 2 

After modifying original (deep copy check):
Original: 999 2 
Copy: 1 2 

After expand test:
5 6 7 
Size: 3
Capacity: 7

Process Completed

*/