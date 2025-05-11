#pragma once
#include <iostream>
#include "Tree.h"

using namespace std;

// структура вершины
struct Node_avl {
    int data;
    int height;
    Node_avl* left;
    Node_avl* right;
};

typedef Node_avl* avltree;

class AVLTree : public Tree
{
private:
    avltree root;

    int height(avltree t);
    // получает высоту поддерева
    void fix_height(avltree t);
    // разность высот правого и левого поддеревьев
    int balance_right_left(avltree t);
    //правый поворот вокруг t
    avltree rotate_right(avltree t);
    //левый поворот вокруг t
    avltree rotate_left(avltree t);
    //балансировка t
    avltree balance(avltree t);
    avltree insert(avltree t, int key, int& count);
    int search_tree(avltree t, int key, int& count);
    void delete_tr(avltree& t1, avltree t, avltree& temp);
    void del_tree(avltree& t, int key, int& count);
    void tree_walk(avltree node);

public:
    AVLTree() { root = NULL; }

    void insertion(int key, int& count) override;
    void deletion(int key, int& count) override;
    int search(int key, int& count) override;
    void tree_walk() override;
};