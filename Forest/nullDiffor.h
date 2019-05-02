#pragma once

#include "Diffor.h"

class nullDiffor : public Diffor {
private:
	nullDiffor();
	~nullDiffor() {}
	static nullDiffor* ins;
public:
	static nullDiffor* get();
	cgNode* run();
	Diffor* clone(cgNode* node);
};
