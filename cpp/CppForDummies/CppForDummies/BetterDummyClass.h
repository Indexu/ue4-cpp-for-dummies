#pragma once

#include "MyDummyClass.h"

class BetterDummyClass : MyDummyClass
{
public:
	void SetPrivateNum(int newNum) override;
};

