#include <iostream>
#include "cgNode/vectorOp/dotNode.h"
#include "cgNode/singleNodes/number/constNode.h"
#include "cgNode/vecNode.h"
#include "cgNode/multiop/sumNode.h"
#include "cgNode/vectorOp/nummulNode.h"

using namespace std;

int main(){
    auto a1 = new constNode(nullptr, 4);
    auto a2 = new constNode(nullptr, 5);
    auto b1 = new constNode(nullptr, 6);
    auto b2 = new constNode(nullptr, 7);
    auto d = new vecNode(nullptr, {a1,a2,b1});
    auto e = new nummulNode(nullptr, b2, d);
    e->compute();

    while(1);
}
