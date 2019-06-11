#include <iostream>
#include "./cgNode/cgNode.h"
#include "cg/cg.h"
#include "linearAlg/Matrix/Matrix.h"
#include "cg/dcg.h"

using namespace std;

int main(){
    auto x = new var(1);
    auto y = new var(2);
    cgNode* node = new lnNode(nullptr, false, new varNode(nullptr, false, y));
    node->get_left()->set_parent(node);
    cg* gr = new cg(node);
    dcg *dgr = new dcg(gr);
    dgr->compute(y);
    auto t = dgr->latest_result();
    while(1);
}
