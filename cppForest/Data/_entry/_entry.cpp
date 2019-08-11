//
// Created by anarion on 2019/8/5.
//

#include "_entry.h"

#include <utility>

_entry::_entry(std::string str) : _str(std::move(str)), is_num(false), is_nan(false) {

}

_entry::_entry(const double num) : _num(num), is_num(true), is_nan(false) {

}

_entry::_entry() : is_nan(true), is_num(false) {

}

bool _entry::check_is_num(const std::string &str) {
    for (char i : str){
        bool f1 = i > '9';
        bool f2 = i < '0';
        if (f1 || f2){
            return false;
        }
    }
    return true;
}

_entry & _entry::operator=(const std::string &str) {
    is_num = false;
    _str = str;
    is_nan = false;
    return *this;
}

_entry &_entry::operator=(double num) {
    is_num = true;
    _num = num;
    is_nan = false;
    return *this;
}

std::string _entry::to_str() {
    if (is_nan){
        return std::move(std::string("NaN"));
    }
    if (is_num){
        return std::move(std::to_string(_num));
    }
    return _str;
}

double & _entry::get_num() {
    return _num;
}

std::string &_entry::get_str() {
    return _str;
}

bool _entry::check_is_blank(const std::string &str) {
    for (char i : str){
        if (i != ' '){
            return false;
        }
    }
    return true;
}
