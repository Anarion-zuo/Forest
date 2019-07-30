//
// Created by anarion on 6/17/19.
//

#include "_single_node.h"
#include "../../MyException/VectorException/singleException/singleException.h"

_single_node::_single_node(_cg_node *parent, _cg_node *child) : _cg_node(parent, std::vector<_cg_node*>(1, child)) {
    if (child){
        if (child->number_child() != 1){
            throw singleException(this);
        }
    }

}

bool _single_node::is_single_val() {
    return true;
}
