#include "cgNode.h"



cgNode::cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d) : left(l), right(r), func(f), diffor(d)
{

}

cgNode::~cgNode() {
	if (func)	delete func;
	if (diffor)	delete diffor;
}
