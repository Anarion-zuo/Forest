#include <iostream>
#include "./cgNode/cgNode.h"

using namespace std;

int main(){
    cgNode* n = new addNode(nullptr, false, new varNode(2), new varNode(3));
    cgNode* m = n->diff();
    while(1);
}
