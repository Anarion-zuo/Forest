//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_CGNODE_H
#define CPPFOREST_CGNODE_H
#include <limits>
#include <vector>
#include "../Garbage_Bin.h"
#include "../Function/Variable/var.h"

class cgNode {
    friend class addNode;
    friend class subNode;
    friend class mulNode;
    friend class divNode;
    friend class expNode;
    friend class lnNode;
    friend class varNode;
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
    virtual var* get_var();

    // clones and changes
    virtual cgNode* clone(cgNode* parent) = 0;
    cgNode* change_this(cgNode* node);
    void change_left(cgNode* node);
    void change_right(cgNode* node);

    // basic numerical processes
    virtual double _compute(double n1, double n2) = 0;
    virtual double compute();
    virtual cgNode* trim() = 0;
    virtual cgNode* diff() = 0;

    // gets sets
    void set_var(double val);
    double get_val();
    void set_parent(cgNode* node);
    cgNode* get_parent();
    void set_lr(bool lr);
    bool get_lr();
    cgNode* get_left();
    cgNode* get_right();

    // destructor
    static void del_node(cgNode*& node);
    virtual void del();

    // search
    static std::vector<var*> find_vars(cgNode* node);
    static void _find_vars_recur(cgNode* node, std::vector<var*>& v);

    // trim
    static cgNode* _change_const(cgNode* node, double n);
    static cgNode* _change_if_both_const(cgNode* node);

    // sum prod
    static cgNode* sum(const std::vector<cgNode*>& nodes);
};

#include "biopNodes/addNode.h"
#include "biopNodes/subNode.h"
#include "biopNodes/mulNode.h"
#include "biopNodes/divNode.h"
#include "leafNode/constNode.h"
#include "leafNode/varNode.h"
#include "monopNodes/monopNode.h"
#endif //CPPFOREST_CGNODE_H
