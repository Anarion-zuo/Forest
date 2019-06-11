#include <iostream>
#include "./cgNode/cgNode.h"
#include "cg/cg.h"
#include "linearAlg/Matrix/Matrix.h"
#include "cg/dcg.h"
#include "Function/Functions/AffineFunction.h"

using namespace std;

int main(){
    auto f = new AffineFunction({1,2,3});
    auto i = f->compute();
    while(1);
}
