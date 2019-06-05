#include <iostream>
#include "./cgNode/cgNode.h"
#include "linearAlg/Matrix/Matrix.h"
using namespace std;

int main(){
    auto a = new Matrix(6, 6, 1);
    auto b = a->clone();
    auto p = Matrix::_strassen_mul(a, b);
    while(1);
}
