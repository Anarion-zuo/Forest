#pragma once

#include "cgNode.h"

class addNode : public cgNode
{
public:
	addNode(cgNode* l, cgNode* r);
};

class subNode : public cgNode
{
public:
	subNode(cgNode* l, cgNode* r);
};

class mulNode : public cgNode
{
public:
	mulNode(cgNode* l, cgNode* r);
};

class divNode : public cgNode
{
public:
	divNode(cgNode* l, cgNode* r);
};

class expNode : public cgNode
{
public:
	expNode(cgNode* l, cgNode* r);
};