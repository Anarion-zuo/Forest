//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_GARBAGE_BIN_H
#define CPPFOREST_GARBAGE_BIN_H

#include <set>
#include "cgNode/cgNode.h"

class cgNode;
class Garbage_Bin {
private:
    static std::set<cgNode*> _node_bin;
    Garbage_Bin() = default;
    ~Garbage_Bin() = default;
public:
    static void clear_bins();
    static void push(cgNode* node);
};


#endif //CPPFOREST_GARBAGE_BIN_H
