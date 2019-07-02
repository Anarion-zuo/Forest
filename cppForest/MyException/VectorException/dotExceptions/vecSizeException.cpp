//
// Created by anarion on 6/18/19.
//

#include "vecSizeException.h"

vecSizeException::vecSizeException(cgNode *node) : nodeException(node) {}

const char *vecSizeException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
    return (std::string("Operating Addition or Dot product on vectors with different numbers of components. Got size [") + std::to_string(_node->get_child(0)->number_child()) + "] and [" + std::to_string(_node->get_child(1)->number_child()) + std::string("].")).c_str();
}
