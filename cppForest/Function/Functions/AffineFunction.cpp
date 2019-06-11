//
// Created by anarion on 6/11/19.
//

#include "AffineFunction.h"

AffineFunction::AffineFunction(const std::vector<double> &as) {
    if (as.empty()){
        return;
    }
    std::vector<cgNode*> li(as.size(), nullptr);
    size_t i = 0;
    for (i = 0; i < li.size(); ++i){
        auto con = new constNode(nullptr, false, as[i]);
        auto v = new var(0);
        auto vn = new varNode(nullptr, true, v);
        auto mn = new mulNode(nullptr, false, con, vn);
        con->set_parent(mn);
        vn->set_parent(mn);
        li[i] = mn;
    }
    _graph = new cg(cgNode::sum(li));
}
