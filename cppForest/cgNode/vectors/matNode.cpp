//
// Created by anarion on 6/23/19.
//

#include "matNode.h"
#include "../../MyException/MatrixException/cnstFormatException/cnstFormatException.h"

matNode::matNode(cgNode *parent, const std::vector<cgNode *> &childs) : vecNode(parent, childs) {
    const size_t size = _childs[0]->number_child();
    for (size_t i = 0; i < _childs.size(); ++i){
        if (size != _childs[i]->number_child()){
            throw cnstFormatException(this, i, _childs[i]->number_child());
        }
    }
}
