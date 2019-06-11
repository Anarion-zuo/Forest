#include <iostream>
#include "./cgNode/cgNode.h"
#include "cg/cg.h"
#include "linearAlg/Matrix/Matrix.h"
#include "cg/dcg.h"
#include "Function/Functions/AffineFunction.h"
#include "Solvers/SolverSetting/SolverSetting.h"
#include "Solvers/Root/Single-Variable/BisectionFinder.h"

using namespace std;

int main(){
    auto f = new AffineFunction({1,3});
    auto range = new Range(-1, 0);
    auto set = new SolverSetting(100000, 1e-3, std::numeric_limits<double>::epsilon() * 1e3, {range});
    auto solver = new BisectionFinder(set);
    solver->solve(f);
    while(1);
}
