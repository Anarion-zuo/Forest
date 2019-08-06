//
// Created by anarion on 2019/8/6.
//

#include <random>
#include "L2Linear.h"
#include "../../cgNode/_var.h"
#include "../../cgNode/singleNodes/number/_var_node.h"
#include "../../cgNode/multiop/_mul_node.h"
#include "../../cgNode/multiop/_sum_node.h"
#include "../../cgNode/singleNodes/number/_const_node.h"

/*
 * these things changes when inputting different frames of data:
 * 1. the value of the data
 * 2. the value of the weights
 * 3. the value of the bias
 */

L2Linear::L2Linear(const DataFrame &X, const DataFrame &negy) : _X(X), _y(negy), _dim(_X.width()) {
    std::vector<_var*> x(_dim + 1, new _var(1)), w(_dim + 1, new _var(1));
    std::vector<_cg_node*> xn(_dim + 1, nullptr), wn(_dim + 1, nullptr);
    std::vector<_cg_node*> wx(_dim + 2, nullptr);// along with negy
    auto negyn = new _const_node(nullptr, 0);
    wx[_dim + 1] = negyn;
    negyn->set_parent(wx[_dim + 1]);
    std::vector<_var_node*> xnn(_dim + 1, nullptr);

    for (size_t i = 0; i <= _dim; ++i){
        xn[i] = new _var_node(wx[i], x[i]);
        wn[i] = new _var_node(wx[i], w[i]);
        xnn[i] = new _var_node(nullptr, x[i]);
        wx[i] = new _mul_node(nullptr, xn[i], wn[i]);
    }
    auto sum = new _sum_node(nullptr, wx);
    auto mul = new _mul_node(nullptr, sum, nullptr);
    sum->set_parent(mul);
    negyn->set_parent(sum);

    _weights = std::move(w);
    _inputs_X = std::move(x);
    _inputs_negy = negyn;
    _node = mul;
    _gradterms = std::move(xnn);
}

void L2Linear::fit() {
    std::default_random_engine engine(1);
    std::uniform_int_distribution<size_t> dist(0, _X.height() - 1);
    std::vector<double> w1(_dim + 1, 1.1), w2(_dim + 1, 1.1);
    while (true) {
        double d;
        size_t rand = dist(engine);
        for (size_t i = 0; i < _dim; ++i){
            _inputs_X[i]->set_val(_X.loc(i, rand));
            _weights[i]->set_val(w2[i]);
        }
        _weights[_dim]->set_val(w2[_dim]);
        _inputs_negy->set_val(-_y.loc(0, rand));
        w1 = w2;
        for (size_t i = 0; i <= _dim; ++i){
            _node->set_child(1, _gradterms[i]);
            _node->compute();
            d = _node->get_result()->get_val();
            w2[i] -= .001 * d;
        }

    }
}
