//
// Created by anarion on 7/1/19.
//

#ifndef CPPFOREST_DOMNODE_H
#define CPPFOREST_DOMNODE_H

#include <vector>
#include <map>
#include <string>

class DOMNode {
protected:
    std::vector<DOMNode*> _childs;
    std::map<std::string, std::string> _attrs;
    const std::string _name;
public:
    DOMNode(const std::string&& name, const std::map<std::string, std::string>&& _attrs, std::vector<DOMNode*>&& _childs);
    virtual ~DOMNode() = default;

};


#endif //CPPFOREST_DOMNODE_H
