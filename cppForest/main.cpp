#include <iostream>
#include <limits>
#include <zconf.h>
#include <bits/fcntl-linux.h>
#include <fcntl.h>
#include "cgNode/vectorOp/_dot_node.h"
#include "cgNode/singleNodes/number/_const_node.h"
#include "cgNode/vectors/_vec_node.h"
#include "cgNode/multiop/_sum_node.h"
#include "cgNode/vectorOp/_nummul_node.h"
#include "cgNode/vectorOp/_vadd_node.h"
#include "cgNode/_var.h"
#include "cgNode/singleNodes/number/_var_node.h"
#include "cgNode/_root_node.h"
#include "cg/_cg.h"
#include "cg/_dcg.h"
#include "Solvers/Range.h"
#include "Solvers/SolverInput.h"
#include "Solvers/Root/singleroot/BisectionRootFinder.h"
#include "cgNode/singleNodes/op/triang/_sin_node.h"
#include "cgNode/singleNodes/op/triang/_cos_node.h"
#include "cgNode/multiop/_mul_node.h"
#include "Solvers/Root/singleroot/FixedPointRootFinder.h"
#include "cgNode/singleNodes/op/_pow_node.h"
#include "Solvers/Root/singleroot/NewtonsRootFinder.h"
#include "Solvers/Root/singleroot/SecantRootFinder.h"
#include "Solvers/Root/singleroot/FalsePositionRootFinder.h"
#include "Matrix/_cnst_mat/_cnst_mat.h"
#include "Matrix/_cnst_mat/_unit_mat.h"
#include "Matrix/_cnst_mat/_cnst_vec.h"
#include "Matrix/_col_mat/_col_mat.h"
#include "Data/DataFrame.h"
#include "Model/LinearModel/L2Linear.h"

using namespace std;

int main(){
//    auto x = new _var(1);
//    auto xn = new _var_node(nullptr, x);
//    auto po = new _pow_node(nullptr, xn, 2);
//    po->set_childs_parents();
//    auto xn2 = new _const_node(nullptr, -2);
//    auto mi = new _sum_node(nullptr, {po, xn2});
//    auto g = new _cg(mi);
//    auto range = new Range(-.965, 2);
//    map<_var*, Range*> ranges;
//    ranges.insert(pair<_var*, Range*>(x, range));
//    auto inp = new SolverInput(ranges, 1e-14, 1e6, 1e-5);
//    auto sol = new FalsePositionRootFinder(g, inp);
//    sol->solve();
//    cout << x->get_val();

    int fd1 = open("/home/anarion/Documents/CSLearning/AI/Forest/cppForest/1.csv", O_CREAT, 777);
    int fd2 = open("/home/anarion/Documents/CSLearning/AI/Forest/cppForest/2.csv", O_CREAT, 777);
    for (size_t i = 0; i < 0xffffffffffff; ++i){

    }
    close(fd1);
    close(fd2);
    auto x = new DataFrame("/home/anarion/Documents/CSLearning/AI/Forest/cppForest/1.csv");
    auto y = new DataFrame("/home/anarion/Documents/CSLearning/AI/Forest/cppForest/2.csv");
    auto s = new L2Linear(*x, *y);
    s->fit();
}
