//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST__VAR_H
#define CPPFOREST__VAR_H

#include <map>
#include <set>

class _var {
private:
    double _val;
    static std::set<_var*> _vars_set;
    static std::map<_var*, _var*> _dvars_map;
    static void clear_dvars();

public:
    explicit _var(double n);
    virtual ~_var();

    static void push_dvars(_var* v1, _var* v2);
    static _var* get_dvar(_var* v);
    static const std::map<_var*, _var*>& get_map();
    _var* register_this();

    void set_val(double n);
    double get_val();

    _var* diff();

    static std::map<_var*,_var*>::iterator set_dvar(_var* v);
    static void clear_dvar(const std::map<_var*,_var*>::iterator& it);
};


#endif //CPPFOREST__VAR_H
