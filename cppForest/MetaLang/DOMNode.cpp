//
// Created by anarion on 7/1/19.
//

#include "DOMNode.h"

DOMNode::DOMNode(const std::string &&name, const std::map<std::string, std::string> &&attrs,
                 std::vector<DOMNode *> &&childs) : _name(name),  _attrs(attrs), _childs(childs){}
