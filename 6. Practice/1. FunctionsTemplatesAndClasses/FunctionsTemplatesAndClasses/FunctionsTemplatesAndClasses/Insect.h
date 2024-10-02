#pragma once
#include "Animal.h"
class Insect {
protected:
	string typeOfSkeleton;
public:
	string getSkeletonType() const{ return this->typeOfSkeleton; }
	virtual void setTypeOfSkeleton(string&) = 0;
};