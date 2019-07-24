//
// Created by anarion on 6/17/19.
//

#ifndef CPPFOREST_CGNODE_H
#define CPPFOREST_CGNODE_H


#include <vector>
#include <deque>
#include "../linearAlg/Array/Array.h"

class cg;
class cgNode {
    friend class cg;
protected:
    std::vector<cgNode*> _childs;
    cgNode* _parent;
    cgNode* _result = nullptr;

    // dust bin
    static std::deque<cgNode*> _node_bin;
    static void _throw_away(cgNode* node);
    static void _clear_bin();
    static void _retrieve_bin();

    // del options
    static void _del_as_node(cgNode*& node);
    static void _del_as_root(cgNode*& node);
    static void _del_as_root_recur(cgNode*& node);

public:
    cgNode(cgNode* parent, const std::vector<cgNode*>& childs);
    virtual ~cgNode();
    virtual cgNode* clone(cgNode* parent) = 0;

    // structure
    size_t number_child();
    cgNode* get_parent();
    void set_parent(cgNode* node);
    virtual void set_childs_parents();
    std::vector<cgNode*>& get_childs();
    cgNode* get_child(size_t index);
    void set_child(size_t index, cgNode* node);
    cgNode* get_result();
    size_t find_in_parent();
    virtual double get_val();
    virtual void set_val(double val);

    static void change_to(cgNode* oldnode, cgNode* newnode);

    // calculation
    virtual void compute() = 0;
    virtual void diff() = 0;
    virtual void trim() = 0;

    // check
    virtual bool is_single_val();
    virtual bool is_const();
    virtual bool is_num();

//    // output
//    virtual std::string&& to_string();
//    virtual const std::string& string_name() = 0;
};


#endif //CPPFOREST_CGNODE_H
