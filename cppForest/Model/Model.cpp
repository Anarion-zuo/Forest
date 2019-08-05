//
// Created by anarion on 2019/8/5.
//

#include "Model.h"

#include <utility>

Model::Model() {

}

//std::vector<double> Model::get_result() {
//    size_t len = _vars.size();
//    std::vector<double> ret(len);
//    for (size_t i = 0; i < len; ++i){
//        ret[i] = _vars[i]->get_val();
//    }
//    return std::move(ret);
//}

Model::Model(_col_mat *data) : _data(data) {

}

