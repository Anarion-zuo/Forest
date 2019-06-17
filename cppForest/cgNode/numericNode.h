//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_NUMERICNODE_H
#define CPPFOREST_NUMERICNODE_H
#include <limits>
#include <vector>
#include "../Garbage_Bin.h"
#include "../Function/Variable/var.h"
#include "cgNode.h"

class numericNode : public cgNode {
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
    numericNode* _left;
    numericNode* _right;
    numericNode* _parent;
    double _val;
    bool _lr;


public:
    numericNode(numericNode* parent, bool lr, numericNode* left, numericNode* right, double val);
    virtual ~numericNode() = default;

    // checks
    virtual bool is_n_node(double n);
    virtual bool is_var();
    virtual bool is_const();
    virtual var* get_var();
    virtual bool is_vector();

    // clones and changes
    virtual numericNode* clone(numericNode* parent) = 0;
    numericNode* change_this(numericNode* node);
    void change_left(numericNode* node);
    void change_right(numericNode* node);

    // basic numerical processes
    virtual double _compute(double n1, double n2) = 0;
    virtual double compute();
    virtual numericNode* trim() = 0;
    virtual numericNode* diff() = 0;

    // gets sets
    void set_var(double val);
    double get_val();
    void set_parent(numericNode* node);
    numericNode* get_parent();
    void set_lr(bool lr);
    bool get_lr();
    numericNode* get_left();
    numericNode* get_right();

    // destructor
    static void del_node(numericNode*& node);
    virtual void del();

    // search
    static std::vector<var*> find_vars(numericNode* node);
    static void _find_vars_recur(numericNode* node, std::vector<var*>& v);

    // trim
    static numericNode* _change_const(numericNode* node, double n);
    static numericNode* _change_if_both_const(numericNode* node);

    // sum prod
    static numericNode* sum(const std::vector<numericNode*>& nodes);
};

#include "biopNodes/addNode.h"
#include "biopNodes/subNode.h"
#include "biopNodes/mulNode.h"
#include "biopNodes/divNode.h"
#include "leafNode/constNode.h"
#include "leafNode/varNode.h"
#include "monopNodes/monopNode.h"
#endif //CPPFOREST_NUMERICNODE_H
