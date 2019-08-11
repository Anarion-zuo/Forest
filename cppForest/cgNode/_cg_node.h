//
// Created by anarion on 6/17/19.
//

#ifndef CPPFOREST__CG_NODE_H
#define CPPFOREST__CG_NODE_H


#include <vector>
#include <deque>
//#include "../linearAlg/Array/Array.h"

class _cg;
class _cg_node {
    friend class _cg;
protected:
    std::vector<_cg_node*> _childs;
    _cg_node* _parent;
    double _val = 0;
//    _cg_node* _result = nullptr;

    // dust bin
    static std::deque<_cg_node*> _node_bin;
    static void _throw_away(_cg_node* node);
    static void _clear_bin();
    static void _retrieve_bin();

    // del options
    static void _del_as_node(_cg_node*& node);
    static void _del_as_root(_cg_node*& node);
    static void _del_as_root_recur(_cg_node*& node);

public:
    _cg_node(_cg_node* parent, std::vector<_cg_node*>  childs);
    _cg_node(_cg_node* parent, std::vector<_cg_node*>  childs, double val);
    virtual ~_cg_node();
    virtual _cg_node* clone(_cg_node* parent) = 0;

    // structure
    size_t number_child();
    _cg_node* get_parent();
    void set_parent(_cg_node* node);
    virtual void set_childs_parents();
    std::vector<_cg_node*>& get_childs();
    _cg_node* get_child(size_t index);
    void set_child(size_t index, _cg_node* node);
    size_t find_in_parent();
    virtual double get_val();
    virtual void set_val(double val);

    static void change_to(_cg_node* oldnode, _cg_node* newnode);

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


#endif //CPPFOREST__CG_NODE_H
