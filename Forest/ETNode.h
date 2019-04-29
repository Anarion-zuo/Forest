#pragma once

#include "TreeNode.hpp"
#include "ETNode_d.h"

struct ETNode : public TreeNode<double>
{
protected:

public:
	ETNode(ETNode* l, ETNode* r, const double& d);
	~ETNode();
};

