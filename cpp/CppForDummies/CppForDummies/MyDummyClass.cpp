#include "MyDummyClass.h"
#include <iostream>

/*
 * This is the cpp file.
 * Here we implement the class functions
 *
 * We need to specify a namespace for each of the implemented functions
 * We do this via the double colon (::) operator 
 */

MyDummyClass::MyDummyClass()
{
    std::cout << "Creating MyDummyClass!" << std::endl;

    num = 5;
    privateNum = 3;
    protectedNum = 2;
}

MyDummyClass::~MyDummyClass()
{
    std::cout << "Destroying MyDummyClass!" << std::endl;
}

int MyDummyClass::GetPrivateNum() const
{
    return privateNum;
}

void MyDummyClass::SetPrivateNum(int newNum)
{
    privateNum = newNum;

    // Can also use 'this' keyword, which is a pointer to the current instance of this class
    this->privateNum = newNum;
}
