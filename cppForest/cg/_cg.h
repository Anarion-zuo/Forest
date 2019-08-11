//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST__CG_H
#define CPPFOREST__CG_H

#include "../cgNode/_cg_node.h"
#include "../cgNode/_root_node.h"

class _cg {
    friend class FixedPointRootFinder;
protected:
    _cg_node* _root;
public:
    explicit _cg(_cg_node* root);
    explicit _cg(_cg* graph);
    virtual ~_cg();
    virtual _cg* clone();

    virtual void compute();
    double get_val();
};

#endif //CPPFOREST__CG_H
