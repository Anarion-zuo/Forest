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
#include "cgNode/singleNodes/op/triang/sinNode.h"
#include "cgNode/singleNodes/op/triang/cosNode.h"
#include "cgNode/multiop/mulNode.h"
#include "Solvers/Root/singleroot/FixedPointRootFinder.h"
#include "cgNode/singleNodes/op/powNode.h"
#include "Solvers/Root/singleroot/NewtonsRootFinder.h"
#include "Solvers/Root/singleroot/SecantRootFinder.h"
#include "Solvers/Root/singleroot/FalsePositionRootFinder.h"

using namespace std;

int main(){
    auto x = new var(1);
    auto xn = new varNode(nullptr, x);
    auto po = new cosNode(nullptr, xn);
    po->set_childs_parents();
    auto xn2 = new varNode(nullptr, x);
    auto mi = new sumNode(nullptr, {po, xn2});
    auto g = new cg(mi);
    auto range = new Range(-1.3, -.6);
    map<var*, Range*> ranges;
    ranges.insert(pair<var*, Range*>(x, range));
    auto inp = new SolverInput(ranges, 1e-14, 1000, 1e-16);
    auto sol = new FalsePositionRootFinder(g, inp);
    sol->solve();
    cout << x->get_val();
}
