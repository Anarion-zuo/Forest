#include <iostream>
#include "./cgNode/cgNode.h"
#include "linearAlg/Matrix/Matrix.h"
using namespace std;

int main(){
    auto a = new Matrix(6, 6, 1);
    auto b = a->clone();
    auto s = b->to_string();
    auto p = Matrix::mul(a, b);

    cout << s << p->to_string();
    while(1);
}
