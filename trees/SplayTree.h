#pragma once
#include <iostream>
#include "Tree.h"

using namespace std;

//структура вершины
struct Node_spl {
    int data;
    Node_spl* left;
    Node_spl* right;
    Node_spl* parent;
};

typedef Node_spl* spltree;

class SplayTree : public Tree
{
private:
    spltree root;

    spltree search_tree(spltree node, int key, int& count);
    // левый поворот вокруг вершины t
    void leftRotate(spltree t);
    // правый поворот вокруг вершины t
    void rightRotate(spltree t);
    //функция перемещения вершины в корень
    void splay(spltree xt);
    spltree maximum(spltree node);
    //соединение двух поддеревьев
    spltree join(spltree t1, spltree t2);
    void tree_walk(spltree node);
    void delete_tree(int key, int& count);

public:

    SplayTree() { root = NULL; }

    void tree_walk() override;
    int search(int key, int& count) override;
    void deletion(int key, int& count) override;
    void insertion(int key, int& count) override;
};