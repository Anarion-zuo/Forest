//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_GARBAGE_BIN_H
#define CPPFOREST_GARBAGE_BIN_H

#include <deque>
#include "cgNode/numericNode.h"

class numericNode;
class Garbage_Bin {
private:
    static std::deque<numericNode*> _node_bin;
    Garbage_Bin() = default;
    ~Garbage_Bin() = default;
public:
    static void clear_bins();
    static void push(numericNode* node);
};


#endif //CPPFOREST_GARBAGE_BIN_H
