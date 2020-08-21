#pragma once

/*
 * This is the header file for the class
 * Here we detail what functions and variables the class has
 */

class MyDummyClass
{
	// By default, class members are private

public:
	// Public members are accessable by those who use the class

	// Constructor - happens when the class is 'created'
	MyDummyClass();

	// Destructor (noted by prefixing tilde ~) - happens when the class is 'destroyed'
	~MyDummyClass();

	int num;

	int GetPrivateNum() const;

	// The virtual keyword means that this function can be overriden by other classes that inherit this class
	virtual void SetPrivateNum(int newNum);

private:
	// Private members are not accessable by those who use the class

	int privateNum;

protected:
	// Protected members are like private, but they are accessable by those who inherit the class

	int protectedNum;
};

