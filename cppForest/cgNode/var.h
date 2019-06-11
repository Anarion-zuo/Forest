//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_VAR_H
#define CPPFOREST_VAR_H

#include <map>

class var {
private:
    double _val;
    static std::map<var*, var*> _temp_dvars;
public:
    var(double n);

    static void push_dvars(var* v1, var* v2);
    static void clear_dvars();
    static var* get_dvar(var* v);
    static const std::map<var*, var*>& get_map();
    var* register_this();

    void set_val(double n);
    double get_val();

    var* diff();
};


#endif //CPPFOREST_VAR_H
