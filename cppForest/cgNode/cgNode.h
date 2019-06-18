//
// Created by anarion on 6/17/19.
//

#ifndef CPPFOREST_CGNODE_H
#define CPPFOREST_CGNODE_H


#include <vector>
#include "../linearAlg/Array/Array.h"

class cgNode {
protected:
    std::vector<cgNode*> _childs;
    cgNode* _parent;
    cgNode* _result = nullptr;
public:
    cgNode(cgNode* parent, const std::vector<cgNode*>& childs);
    virtual ~cgNode()= default;
    virtual cgNode* clone(cgNode* parent) = 0;

    // structure
    size_t number_child();
    cgNode* get_parent();
    void set_parent(cgNode* node);
    void set_childs_parents();
    std::vector<cgNode*>& get_childs();
    double get_child(size_t index);
    cgNode* get_result();
    size_t index_parent();
    virtual double get_val();
    virtual void set_val(double val);

    // calculation
    virtual void compute() = 0;
    virtual void diff() = 0;
    virtual void trim() = 0;

    // check
    virtual bool is_single_val();

    // output
    virtual std::string&& to_string() = 0;
};


#endif //CPPFOREST_CGNODE_H
