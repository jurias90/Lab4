/**
Lab #3
    Group CPP2
    Team Memebers: Jesus Urias, Nhung Vo
    Purpose: The purpose of this lab is implement a modular ADT for any currency
**/
#ifndef LINKNODE_H
#define LINKNODE_H
#include "Currency.h"

struct LinkNode {
    LinkNode() =default;
    explicit LinkNode(Currency* newData) : data(newData) {};
    ~LinkNode() {}
    Currency *data=nullptr;
    LinkNode *next=nullptr;
};

#endif //LINKNODE_H
