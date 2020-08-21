// CppForDummies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Includes are code files or modules which are imported

#include <iostream>
#include <array>
#include "MyDummyClass.h"
#include "BetterDummyClass.h"

void Pointers()
{
    /*
     * Pointers are variables that "point" to a specific memory address. Their value is the memory address itself, not the data the memory address contains.
     *      You've probably somewhere seen something like 0xffffffff. That's a memory address.
     * 
     * Pointer types are indicated with the * symbol
     * 
     * Pointers can be de-referenced with the same symbol, *.
     *      De-referencing means attempting to read the data the pointer points to.
     * 
     * Pointers can be created via the ampersand symbol, &
     *      Ampersand is the operator used to get memory addresses of variables
     */

    int num = 5;

    int* numPtr = &num;

    std::cout << "Pointers - Original num: " << num << std::endl;
    std::cout << "Pointers - Pointer num: " << numPtr << std::endl;
    std::cout << "Pointers - Pointer num data: " << *numPtr << std::endl;

    *numPtr = 112;

    std::cout << "Pointers - Original num: " << num << std::endl;
    std::cout << "Pointers - Pointer num: " << numPtr << std::endl;
    std::cout << "Pointers - Pointer num data: " << *numPtr << std::endl;

    // Since the pointer points to the memory address of 'num', any changes done to the data the pointer points to will reflect on 'num'

    MyDummyClass myClass;
    auto classPtr = &myClass;

    // We can dereference the pointer and then use the class as normal using dot-notation
    (*classPtr).SetPrivateNum(1);

    // We can also use the arrow notation -> which will do the same
    classPtr->SetPrivateNum(1);
}

void Classes()
{
    // Nested scope to show-case destructor
    {
        // First we create the class, this automatically calls the class construtor
        MyDummyClass myClass;

        std::cout << "Classes - Num value before setting: " << myClass.num << std::endl;
        myClass.num = 20;
        std::cout << "Classes - Num value after setting: " << myClass.num << std::endl;

        std::cout << "Classes - Private num value before setting: " << myClass.GetPrivateNum() << std::endl;
        myClass.SetPrivateNum(99);
        std::cout << "Classes - Private num value after setting: " << myClass.GetPrivateNum() << std::endl;

    }
    // Now since we went out of the scope where the class lived, the destructor is automatically called

    // Create the class that inherited MyDummyClass
    // Note that it still outputs the stuff from the MyDummyClass constructor
    BetterDummyClass myClass;
    myClass.SetPrivateNum(11);
}

void Arrays()
{
    /*
     * Arrays are basically lists of data
     * 
     * Strictly speaking, arrays have a fixed size and cannot be shrunk or expanded.
     * This is due to how it's layed out in memory.
     * 
     * In UE4, the TArray class can shrink and expand, so you don't need to think about it
     */

    // Create an array of 10 integers
    std::array<int, 10> myArray = { 20,21,22,23,24,25,26,27,28,29 };

    std::cout << "Arrays - First value: " << myArray[0] << std::endl;
    std::cout << "Arrays - Second value: " << myArray[1] << std::endl;

    /*
     * C++ classes, like std::array have functions which you can call, like array.size()
     * We can use that to loop over the array without going out-of-bounds (past the size of the array)
     */

    for (auto i = 0; i < myArray.size(); i++)
    {
        std::cout << "Arrays - Standard for loop: " << myArray[i] << std::endl;
    }

    /*
     * A much safer and nicer way to loop over arrays is by using a "for-each" loop using the colon (:) operator
     * Most collections (arrays, lists, queues, maps, etc...) have support for this.
     * UE4 TArray, TMap, etc... have support for this
     */

    for (auto val : myArray)
    {
        std::cout << "Arrays - Colon operator loop: " << val << std::endl;
    }
}

void Loops()
{
    /*
     * For loop
     * 
     * for (int i = 0; i < 10; i++) { ... }
     * 
     * The structure of the for loop is split into 3 parts
     *      - Initialization
     *          int i = 0
     * 
     *      - Boolean check that happens at the beginning of every iteration/loop
     *          i < 10
     *          'i' less than 10
     * 
     *          If true, carry on with the loop
     *          If false, stop looping
     * 
     *      - An increment step that happens at the end of every iteration/loop
     *          i++
     *          Increase 'i' by 1. Same as i += 1 or i = i + 1
     *          Note that the code here can be anything. It's just executed at the end of every iteration/loop and is intended as an incremental step
     *      
     */

    // Basic for loop that loops 10 times
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Loops - Basic for loop: " << i << std::endl;
    }

    // for loop that loops 5 times due to stepping over every other number
    for (auto i = 0; i < 10; i += 2)
    {
        std::cout << "Loops - Step over for loop: " << i << std::endl;
    }

    /*
     * While loop
     * 
     * Loops until condition is false
     */
    auto i = 0;
    while (i < 10) {
        std::cout << "Loops - While loop: " << i << std::endl;

        i++;
    }

    /*
     * Do while loop
     *
     * Skips checking the condition for the first iteration and then loops until condition is false
     *      Shoot first, ask questions later
     */
    i = 0;
    do {
        std::cout << "Loops - Do while loop: " << i << std::endl;

        i++;
    } while (i == 1);

    /*
     * If we want to exit a loop entirely, we can use the 'break' keyword
     * If we want to exit only a specific iteration, we can use the 'continue' keyword
     */
    for (auto i = 0; i < 100; i++)
    {
        // If the remainder of the division i / 2 is zero, skip this iteration
        // This is a very common line of code. Any number with no remainder after a division with 2, is an even number
        // Therefor, this will be true only for even numbers
        if (i % 2 == 0)
        {
            continue;
        }

        // Only odd numbers here

        // If i is 7, we exit the loop
        if (i == 7)
        {
            break;
        }

        std::cout << "Loops - Break/Continue loop: " << i << std::endl;
    }
}

void Flow()
{
    // if condition - if the condition in the parenthesis is true, we go inside
    if (3 > 2)
    {
        std::cout << "Flow - if" << std::endl;
    }

    // We go into the else block if the condition is false
    if (10 < 2)
    {
        std::cout << "Flow - if - true" << std::endl;
    }
    else 
    {
        std::cout << "Flow - if - else" << std::endl;
    }

    // We can add any number of else-if blocks in between the first if and the else block
    // Note that the else block is entirely optional
    if (10 < 2)
    {
        std::cout << "Flow - if - true" << std::endl;
    }
    else if (55 > 2)
    {
        std::cout << "Flow - if - else if" << std::endl;
    }
    else
    {
        std::cout << "Flow - if - else" << std::endl;
    }

    /*
     * Switch blocks can be thought of as a router
     * You feed it a variable and it will go into the case that it equals
     * If nothing matches, it will use the default block if provided
     * 
     * You can continue to test for more cases by skipping the break statement
     */

    auto num = 5;
    switch (num) {
        case 1:
            std::cout << "Flow - Switch 1" << std::endl;
            break;

        case 3:
            std::cout << "Flow - Switch 3" << std::endl;
            break;

        case 8:
            std::cout << "Flow - Switch 8" << std::endl;
            // No break here, will continue into case 5, similar to case13-14

        case 5:
            std::cout << "Flow - Switch 5" << std::endl;
            break;

        case 13:
        case 14:
            // Will match both 13 and 14
            std::cout << "Flow - Switch 13 14" << std::endl;
            break;

        default:
            // Default is optional
            std::cout << "Flow - Switch default" << std::endl;
            break;
    }
}

void Scope()
{
    // Scope is also known as 'block'

    // We can use the variable name 'num' here even though that name is used for variables in other functions
    auto num = 0;

    // Curly brackets is called a scope
    {
        auto num2 = 0;
    }

    // num2 doesn't exist here since we are no longer within in the scope it was declared

    {
        // 'num' exists here since we're still inside the scope it's declared
        // We can name this variable num2 even though the scope above also used that name
        // Names must be unique within their scope
        // You can create as many nested scopes as you want
        auto num2 = num;

        {
            {
                {
                    {
                        {
                            {
                                {
                                    // This is legal in C++
                                    auto num3 = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Again, here we exited the scope for num2, so we can't use it

    // Functions all create their own scope
}

void MultipleReturn(int& four, int& three)
{
    // We can exploit pass by reference to return multiple values
    // The function doesn't care about the existing values in these variables, it will just assign new values to them
    // Unreal Engine uses this pattern a lot

    four = 4;
    three = 3;
}

void ConstantParameter(const int& num)
{
    // A slight optimization to functions is passing any variables the function doesn't change to be constant and passing them by reference
    // Less copying = faster and more memory efficient

    // Error, can't change a constant
    // num = 2;
}

void PassByReference(int& num)
{
    // Pass by reference means the actual variable will be used in the function, no copying
    // Any changes to the variable will be made to the original variable
    // Pass by reference is actually passing the memory address of the variable, the ampersand symbol '&' generally means "I want the memory address of this variable"

    num = 2;
}

void PassByValue(int num)
{
    // Pass by value means the value of the parameter variable will be copied when used in the function
    // Any changes made to the variable will be made to the copy, not the original

    num = 2;
}

int Multi(int num1, int num2)
{
    return num1 * num2;
}

int QuickMaths()
{
    return 2 + 2 - 1;
}

void VoidReturnValue()
{
    // Print 'Hello World'
    std::cout << "Hello World!\n";
}

void Functions()
{
    /*
     * Functions are called via the () operator, yes even that is an operator
     */

    // Void return value means nothing is returned. No return value
    VoidReturnValue();

    // Assigning return value to int variable
    int result = QuickMaths();
    std::cout << "Functions - Quick maths int variable: " << result << std::endl;

    // Assigning return value to auto variable
    auto result2 = QuickMaths();
    std::cout << "Functions - Quick maths auto variable: " << result2 << std::endl;

    // Don't need to assign to specific variable to be used
    std::cout << "Functions - Quick maths return value: " << QuickMaths() << std::endl;

    // Function paramater
    std::cout << "Functions - QuadrupleInput return value: " << Multi(5, 4) << std::endl;

    // Pass by value vs Pass by reference
    auto myNum = 8;

    PassByValue(myNum);
    std::cout << "Functions - After PassByValue: " << myNum << std::endl;

    PassByReference(myNum);
    std::cout << "Functions - After PassByReference: " << myNum << std::endl;

    // Multiple return
    int multiReturn1;
    int multiReturn2;

    MultipleReturn(multiReturn1, multiReturn2);
    std::cout << "Functions - After MultipleReturn: " << multiReturn1 << " " << multiReturn2 << std::endl;
}

void Operators()
{
    /*
     * Basic operators
     * 
     * = Assignment
     * 
     * + Addition
     * - Subtraction
     * * Multiplication
     * / Division
     * % Modulus (The remainder from division)
     * 
     * Assignment operator along with any operator here above means to perform the operation and then assign the result to the variable
     *      num += 3 (Add 3 to the value of num and assign it to num)
     * 
     * ++ Increment (Add 1)
     * -- Decrement (Subtract 1)
     */

    auto num = 5;

    std::cout << "Operators - Num: " << num << std::endl;

    // Add 3
    num = num + 3;
    std::cout << "Operators - Num: " << num << std::endl;

    // Add 2
    num += 2;
    std::cout << "Operators - Num: " << num << std::endl;

    // Increment by 1
    num++;
    std::cout << "Operators - Num: " << num << std::endl;

    // Decrement by 1
    num--;
    std::cout << "Operators - Num: " << num << std::endl;

    // Subtract 2
    num -= 2;
    std::cout << "Operators - Num: " << num << std::endl;

    // Subtract 3
    num = num - 3;
    std::cout << "Operators - Num: " << num << std::endl;
}

void Variables()
{
    /*
     * Binary and bytes
     * 
     * There are 8 bits in 1 byte
     * Binary is a method of data representation using only 1's and 0's
     * 
     * |  128  |  64  |  32  |  16  |  8  |  4  |  2  |  1  |
     *     0       0      0      0     0     0     0     0     =    0
     *     0       0      0      0     0     0     0     1     =    1
     *     0       0      0      0     0     0     1     0     =    2
     *     0       0      0      0     0     0     1     1     =    2 + 1 = 3
     *     0       0      0      0     0     1     0     0     =    4
     *     0       0      0      0     0     1     0     1     =    4 + 1 = 5
     *     0       0      0      0     0     1     1     0     =    4 + 2 = 6
     *     0       0      0      0     0     1     1     1     =    4 + 2 + 1 = 7
     *     0       0      0      0     1     0     0     0     =    8
     *     .........
     *     .........
     *     1       1      1      1     1     1     1     1     =    128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 255
     * 
     * We can use 2 by the power of number of bits and subtract 1 from the result to get the maximum value
     *   (2^8) - 1 = 255
     *
     * However, the most significant bit, 128 in the example above, is often used as a 'sign' bit.
     * The sign bit tells us whether the number is positive or negative.
     *      Check out "Ones' Complement" if you are curious why the negative range is always 1 larger than the positive range
     *      https://en.wikipedia.org/wiki/Ones%27_complement
     *
     * When the sign bit is used, a variable is signed.
     * When it's not used, it's unsigned
     * int num1 = 4
     * unsigned int num2 = 4
     * 
     * Usually you don't need to think about unsigned variables unless you are dealing with massive numbers
     */

    /*
     * Boolean (bool) variables are true/false with a size of 1 byte (8 bits)
     * 
     * Can only store one of 2 values, either 'true' or 'false'
     * 
     * If you are curious about why it's 1 byte and note just 1 bit, then it's due to memory alignment in RAM and various caches
     */
    bool yes = true;

    /*
     * Character (char) variables are a single character with a size of 1 byte (8 bits)
     *
     * Can only store 1 character at a time
     * 
     * Must use single quotes
     * 
     * Behind the scenes, it's actually an integer number.
     *      See for example the ASCII table: http://www.asciitable.com/
     * 
     * wchar_t is a char type with a size of 2 bytes that is used for some special characters, not often used.
     * 
     */
    char character = 'p';

    /*
     * String variables are variables with varying byte size
     *
     * Is actually a series of char variables
     *
     * Must use double quotes
     *
     * Neither C nor C++ has a an official 'string' type.
     *      Example below for std::string (Standard Libarary string)
     *      UE4 implements its own string type, 'FString'
     */
    std::string str = "yay";

    // ==== Numbers ====

    /*
     * Short (same as short int) variables are whole numbers with a size of 2 bytes (16 bits)
     * 
     * Max signed positive number = 32,767 (32 thousand)
     * Min signed negative number = -32,768
     * 
     * Max unsigned number = 65,535 (65 thousand)
     * 
     * Fun fact: The network port range is an unsigned short
     * 
     * The short variable type is rarely used.
     * If you care about saving a couple of bytes here and there, you might use it.
     */
    short shortNumber = 8987;

    /* Integers (int) are whole numbers with a size of 4 bytes (32 bits)
     * 
     * Max positive number = 2,147,483,647 (2.1 billion)
     * Min negative number = -2,147,483,648
     * 
     * Max unsigned number = 4294967295 (4.2 billion)
     * 
     * Should be the default for whole numbers.
     */
    int intNumber = 8489;

    /* Long long (same as long long int) are whole numbers with a size of 8 bytes (64 bits)
     *
     * Max positive number = 9,223,372,036,854,775,807 (9.2 quintiliion)
     * Min negative number = -9,223,372,036,854,775,808
     *
     * Max unsigned number = 18,446,744,073,709,551,615 (18.4 quintiliion)
     * 
     * Long long is rarely used, unless you require absolutely massive number ranges.
     */
    long long longNumber = 1337;

    /* Float are fractional numbers with a size of 4 bytes (32 bits)
     *
     * Max positive number = 340,282,346,638,528,859,811,704,183,484,516,925,440 (340.2 undecillion)
     * Min negative number = -340,282,346,638,528,859,811,704,183,484,516,925,440
     *
     * Floating point numbers have no unsigned variants.
     *
     * In general, 7 decimal digits precision.
     * Must be suffixed with the letter 'f'
     * 
     * Even though the maximum number is huge, the range is not.
     * Once you go up to some pretty big numbers, some rounding will happen and even whole numbers will be skipped.
     *      This is what people refer to as a "floating-point error"
     *      This is due to how it's represented in binary form.
     *      For more in-depth information: http://steve.hollasch.net/cgindex/coding/ieeefloat.html
     */
    float floatNumber = 5.89f;

    /* Double are fractional numbers with a size of 8 bytes (64 bits)
     *
     * Max positive number = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368
     * Min negative number = -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368
     *
     * In general, 15 decimal digits precision.
     * Must NOT be suffixed with the letter 'f'
     * 
     * double is just float, but bigger.
     * 
     * Double is generally recommended over float in C++ projects.
     *      In game engines though, float seems to be preferred
     *      Could be related to GPU performance
     */
    double doubleNumber = 98.45;

    /* Long Double are fractional numbers with a size of 12 bytes (96 bits)
     *
     * Max positive number = ???
     * Min negative number = ???
     *
     * Not commonly used.
     * 
     * Must suffix with the letter 'L'
     */
    long double yugeNumber = 5555.888L;

    // === Auto ===
    
    /*
     * The 'auto' keyword is used when you can't be bothered to declare the variable type explicitly
     * During compilation of the code, the compiler will deduce the variable type.
     * 
     * I highly recommend using it when possible
     */
    auto autoBool = false;
    auto autoChar = 'w';
    auto autoInt = 5;
    auto autoFloat = 5.5f;
    auto autoDouble = 5.5;

    // === Constants ===

    /*
     * Constant variables cannot have their values changed
     */
    const auto gravity = 9.8f;

    // Can't re-assign 'gravity'
    // gravity = 7.0f;

    auto nonConstantGravity = gravity;
    nonConstantGravity = 7.0f;
}

int main()
{
    // Print 'Cpp For Dummies!', followed by a new line
    // \n is called the newline character
    std::cout << "Cpp For Dummies!\n";

    Variables();
    Operators();
    Functions();
    Scope();
    Flow();
    Loops();
    Arrays();
    Classes();
    Pointers();
}
