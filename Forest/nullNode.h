#pragma once
#include "cgNode.h"
class nullNode : public cgNode {
private:
	nullNode();
	~nullNode() {}
	static nullNode* ins;
public:
	static nullNode* get();
};