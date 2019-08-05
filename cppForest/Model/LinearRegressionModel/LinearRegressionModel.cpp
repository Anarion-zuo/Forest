//
// Created by anarion on 2019/8/5.
//

#include "LinearRegressionModel.h"
#include "../../cgNode/singleNodes/number/_var_node.h"
#include "../../cgNode/multiop/_mul_node.h"
#include "../../cgNode/multiop/_sum_node.h"

LinearRegressionModel::LinearRegressionModel(_col_mat *data) : Model(data), _dim(data->width()){
    size_t dim = _dim;
    std::vector<_cg_node*> ret(dim + 1);
    _coeff.resize(dim + 1);
    _input.resize(dim);
    for (size_t i = 0; i < dim; ++i){
        auto v = new _var(0);
        auto vn = new _var_node(nullptr, v);
        _coeff[i] = v;
        v = new _var(0);
        auto vn2 = new _var_node(nullptr, v);
        _input[i] = v;
        ret[i] = new _mul_node(nullptr, vn, vn2);
        vn->set_parent(ret[i]);
        vn2->set_parent(ret[i]);
    }
    auto v = new _var(0);
    auto vn = new _var_node(nullptr, v);
    *(_coeff.end() - 1) = v;
    *(ret.end() - 1) = vn;
    auto root = new _sum_node(nullptr, ret);
    auto graph = new _cg(root);
    _target = graph;
    graph = graph->clone();
    _dtarget = new _dcg(graph);

}

void LinearRegressionModel::fit() {

}
