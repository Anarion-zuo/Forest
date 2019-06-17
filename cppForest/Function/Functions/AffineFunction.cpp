//
// Created by anarion on 6/11/19.
//

#include "AffineFunction.h"

AffineFunction::AffineFunction(const std::vector<double> &as) {
    if (as.empty()){
        return;
    }
    std::vector<numericNode*> li(as.size() - 1, nullptr);
    auto first = new constNode(nullptr, false, as[0]);
    if (as.size() == 1){
        _graph = new cg(first);
        return;
    }
    auto root = new addNode(nullptr, false, first, nullptr);
    first->set_parent(root);
    for (size_t i = 0; i < li.size(); ++i){
        auto con = new constNode(nullptr, false, as[i + 1]);
        auto v = new var(0);
        auto vn = new varNode(nullptr, true, v);
        auto mn = new mulNode(nullptr, false, con, vn);
        con->set_parent(mn);
        vn->set_parent(mn);
        li[i] = mn;
    }
    root->change_right(numericNode::sum(li));
    _graph = new cg(root);
}
