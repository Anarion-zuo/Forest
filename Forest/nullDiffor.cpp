#include "nullDiffor.h"

nullDiffor::nullDiffor() : Diffor(nullNode::get()) {}

nullDiffor* nullDiffor::ins = new nullDiffor;

nullDiffor* nullDiffor::get()
{
	return ins;
}
cgNode* nullDiffor::run() { return p; }
Diffor* nullDiffor::clone(cgNode* node) { return this; }