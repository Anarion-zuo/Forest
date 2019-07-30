//
// Created by anarion on 6/23/19.
//

#include "nummulTypeException.h"

nummulTypeException::nummulTypeException(_cg_node *node) : nodeException(node) {

}

const char *nummulTypeException::what() const _GLIBCXX_USE_NOEXCEPT {
    return "Trying to multiply a number and a vector through \"_nummul_node\". Try _dot_node instead.";
}
