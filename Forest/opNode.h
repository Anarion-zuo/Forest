#pragma once

#include "cgNode.h"

class addNode : public cgNode
{
public:
	addNode(cgNode* l, cgNode* r);
	cgNode* clone();
};

class subNode : public cgNode
{
public:
	subNode(cgNode* l, cgNode* r);
	cgNode* clone();
};

class mulNode : public cgNode
{
public:
	mulNode(cgNode* l, cgNode* r);
	cgNode* clone();
};

class divNode : public cgNode
{
public:
	divNode(cgNode* l, cgNode* r);
	cgNode* clone();
};

class expNode : public cgNode
{
public:
	expNode(cgNode* l, cgNode* r);
	cgNode* clone();
};