//
// Created by anarion on 6/23/19.
//

#include "getnonconstValException.h"

getnonconstValException::getnonconstValException(_cg_node *node) : nodeException(node) {}

const char *getnonconstValException::what() const _GLIBCXX_USE_NOEXCEPT {
    return "Trying to get the \"_val\" from a non-const node. Try \"compute()\".";
}
