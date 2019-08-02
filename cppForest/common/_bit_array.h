//
// Created by anarion on 2019/8/2.
//

#ifndef CPPFOREST__BIT_ARRAY_H
#define CPPFOREST__BIT_ARRAY_H


#include <cstddef>

class _bit_array {
protected:
    long* _ptr;
    size_t _size;
public:
    explicit _bit_array(size_t size);
    ~_bit_array();

    void set_bit(size_t index);
    bool get_bit(size_t index);
    void clear_bit(size_t index);
    void set_all();
    void clear_all();

    void resize(size_t size);
};


#endif //CPPFOREST__BIT_ARRAY_H
