//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST__ENTRY_H
#define CPPFOREST__ENTRY_H


#include <string>

class _entry {
public:
    std::string _str;
    double _num = 0;
    bool is_num, is_nan;
    explicit _entry(std::string  str);
    explicit _entry(double num);
    _entry();
    virtual ~_entry() = default;

    static bool check_is_num(const std::string& str);
    static bool check_is_blank(const std::string &str);
    _entry & operator= (const std::string& str);
    _entry & operator= (double num);

    double & get_num();
    std::string& get_str();

    std::string to_str();
};


#endif //CPPFOREST__ENTRY_H
