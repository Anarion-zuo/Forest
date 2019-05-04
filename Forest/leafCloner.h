#pragma once
#include "Cloner.h"
class leafCloner
{
private:
	leafCloner();
	~leafCloner();
public:
	static cgNode* run(cgNode* node);
};

