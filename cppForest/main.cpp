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
#include "cg/cg.h"
#include "cg/dcg.h"
#include "Solvers/Range.h"

using namespace std;

int main(){
    var* x = new var(3);
    var* y = new var(6);

    auto v1 = new vecNode(nullptr, {new varNode(nullptr, x), new varNode(nullptr, x)});
    auto v2 = new vecNode(nullptr, {new varNode(nullptr, y), new varNode(nullptr, y)});

    auto c = new dotNode(nullptr, v1, v2);
    cg* g = new cg(c);

    auto dg = new dcg(g);
    dg->compute(x);

    auto ra = new Range(0, 1);
    auto li = ra->list(0.1);

    while(1);
}
