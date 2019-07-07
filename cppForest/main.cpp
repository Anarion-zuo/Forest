#include <iostream>
#include "cgNode/vectorOp/dotNode.h"
#include "cgNode/singleNodes/number/constNode.h"
#include "cgNode/vectors/vecNode.h"
#include "cgNode/multiop/sumNode.h"
#include "cgNode/vectorOp/nummulNode.h"
#include "cgNode/vectorOp/vaddNode.h"
#include "cgNode/var.h"
#include "cgNode/singleNodes/number/varNode.h"
#include "cgNode/rootNode.h"

using namespace std;

int main(){
    var* x = new var(3);
    var* y = new var(6);

    auto v1 = new vecNode(nullptr, {new varNode(nullptr, x), new varNode(nullptr, x)});
    auto v2 = new vecNode(nullptr, {new varNode(nullptr, y), new varNode(nullptr, y)});

    auto c = new dotNode(nullptr, v1, v2);
    auto d = new rootNode(c);
    d->set_childs_parents();
    d->compute();
    d->diff();
    d->compute();
    while(1);
}
