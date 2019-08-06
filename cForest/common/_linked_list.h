//
// Created by anarion on 2019/8/6.
//

#ifndef CFOREST__LINKED_LIST_H
#define CFOREST__LINKED_LIST_H

struct _linked_node{
    struct _linked_node *prev, *next;
    void *dat;
};

struct _linked_list{
    struct _linked_node *piv;
};

#endif //CFOREST__LINKED_LIST_H
