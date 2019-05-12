//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_CGNODE_H
#define CPPFOREST_CGNODE_H
#include <limits>
#include "../Garbage_Bin.h"

class cgNode {
    friend class addNode;
    friend class subNode;
    friend class mulNode;
    friend class divNode;
    friend class expNode;
    friend class lnNode;
private:
    bool num_equals(double n1, double n2);
protected:
    cgNode* _left;
    cgNode* _right;
    cgNode* _parent;
    double _val;
    bool _lr;


public:
    cgNode(cgNode* parent, bool lr, cgNode* left, cgNode* right, double val);
    virtual ~cgNode() = default;

    // const var checks
    virtual bool is_n_node(double n);
    virtual bool is_var();
    virtual bool is_const();

    virtual cgNode* clone(cgNode* parent) = 0;
    cgNode* change_this(cgNode* node);

    virtual double compute(double n1, double n2) = 0;
    virtual cgNode* trim() = 0;
    virtual cgNode* diff() = 0;

    void set_var(double val);
    double get_val();
    cgNode* get_parent();
    bool get_lr();
    cgNode* get_left();
    cgNode* get_right();

    static void del_node(cgNode*& node);
    virtual void del();
};

#include "addNode.h"
#include "subNode.h"
#include "mulNode.h"
#include "divNode.h"
#include "constNode.h"
#include "varNode.h"
#endif //CPPFOREST_CGNODE_H
