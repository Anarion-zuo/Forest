//
// Created by anarion on 2019/7/30.
//

#include "_cnst_vec.h"

_cnst_vec::_cnst_vec() : _cnst_mat() {}

_cnst_vec::_cnst_vec(double n, size_t dm) : _cnst_mat(n, dm, 1) {}

_cnst_vec::_cnst_vec(size_t dm) : _cnst_mat(0.0, dm, 1) {}
