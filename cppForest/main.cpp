#include <iostream>
#include <limits>
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
#include "Solvers/SolverInput.h"
#include "Solvers/Root/singleroot/BisectionRootFinder.h"

using namespace std;

int main(){
    var* x = new var(3);
    auto xn = new varNode(nullptr, x);
    auto c = new constNode(nullptr, 4);
    auto y = new sumNode(nullptr, {xn, c});
    y->set_childs_parents();

    cg* g = new cg(y);

    auto range = new Range(-4.02, -3.9003);
    map<var*, Range*> m;
    m.insert(pair<var*, Range*>(x, range));
    auto input = new SolverInput(m, 1e-8, 1e10, numeric_limits<double>::epsilon() * 100);
    auto sol = new BisectionRootFinder(g, input);
    sol->solve();

    while(1);
}
