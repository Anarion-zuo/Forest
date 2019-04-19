#pragma once

#include "TreeNode.hpp"
#include "ETNode_d.h"

struct ETNode : public TreeNode<ETNode_d>
{
public:
	ETNode(ETNode* l, ETNode* r, const ETNode_d& v);
	~ETNode();
};

