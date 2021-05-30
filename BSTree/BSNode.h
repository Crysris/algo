//
// Created by 夏天的风 on 2021/5/29.
//
#pragma once
template <class T>
class BSNode {
public:
    T key;
    BSNode<T> *left;
    BSNode<T> *right;
    explicit BSNode(T k) ;
    BSNode(T k, BSNode<T> *l, BSNode<T> *r);
    ~BSNode();
};