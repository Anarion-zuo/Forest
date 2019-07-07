//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_VAR_H
#define CPPFOREST_VAR_H

#include <map>
#include <set>

class var {
private:
    double _val;
    static std::set<var*> _vars_set;
    static std::map<var*, var*> _dvars_map;
    static void clear_dvars();

public:
    explicit var(double n);
    virtual ~var();

    static void push_dvars(var* v1, var* v2);
    static var* get_dvar(var* v);
    static const std::map<var*, var*>& get_map();
    var* register_this();

    void set_val(double n);
    double get_val();

    var* diff();

    static std::map<var*,var*>::iterator set_dvar(var* v);
    static void clear_dvar(const std::map<var*,var*>::iterator& it);
};


#endif //CPPFOREST_VAR_H
