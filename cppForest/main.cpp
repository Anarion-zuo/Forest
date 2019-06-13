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
    auto f = new AffineFunction({1,1});
    auto range = new Range(-2, -0.3);
//    auto set = new SolverSetting(100000, 1e-3, std::numeric_limits<double>::epsilon() * 1e3, {range});
//    auto solver = new BisectionFinder(set);
//    solver->solve(f);
    double res = 0;
    for (long i = 0; i < 99; i += 1){
        res = f->compute({1, (double)i});
    }
    while(1);
}
