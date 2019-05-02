#include "nullNode.h"

nullNode::nullNode() : cgNode(nullptr, nullptr, nullFunctor::get(), nullDiffor::get(), 0) {}

nullNode* nullNode::ins = new nullNode;

nullNode* nullNode::get()
{
	return ins;
}