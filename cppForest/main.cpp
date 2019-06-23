#include <iostream>
#include "cgNode/vectorOp/dotNode.h"
#include "cgNode/singleNodes/number/constNode.h"
#include "cgNode/vectors/vecNode.h"
#include "cgNode/multiop/sumNode.h"
#include "cgNode/vectorOp/nummulNode.h"

using namespace std;

int main(){
    auto a1 = new constNode(nullptr, 3);
    auto a2 = new constNode(nullptr, 6);
    auto a3 = new constNode(nullptr, 88);
    auto b = new sumNode(nullptr, {a1, a2, a3});
    b->set_childs_parents();
    auto c1 = new constNode(nullptr, 3);
    auto c2 = new constNode(nullptr, 6);
    auto c3 = new constNode(nullptr, 88);
    auto c = new vecNode(nullptr, {c1, c2, c3});
    c->set_childs_parents();
    auto d = new nummulNode(nullptr, c, b);
    d->compute();

    while(1);
}
