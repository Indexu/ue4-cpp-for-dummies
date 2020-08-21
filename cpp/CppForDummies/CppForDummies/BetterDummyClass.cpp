#include "BetterDummyClass.h"
#include <iostream>

void BetterDummyClass::SetPrivateNum(int newNum)
{
    // We can call the already implemented function of our parent class like so
    // Note we use the namespace MyDummyClass
    MyDummyClass::SetPrivateNum(newNum);

    // We can now do other stuff, like use that protected variable

    std::cout << "Just because, here's the protected variable: " << protectedNum << std::endl;
}
