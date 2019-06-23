//
// Created by anarion on 6/17/19.
//

#include "singleNode.h"
#include "../../MyException/VectorException/singleException/singleException.h"

singleNode::singleNode(cgNode *parent, cgNode *child) : cgNode(parent, std::vector<cgNode*>(1, child)) {
    if (child){
        if (child->number_child() != 1){
            throw singleException(this);
        }
    }

}

bool singleNode::is_single_val() {
    return true;
}
