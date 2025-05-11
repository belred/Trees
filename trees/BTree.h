#pragma once
#include <iostream>
#include "Tree.h"

using namespace std;

// стукрутра узла и операции над ним
class Node_b {
private:
    int* data; //массив значений
    int t; //входной параметр t
    Node_b** C; //потомки
    int n; //количество ключей
    bool leaf; //лист

public:
    Node_b(int _t, bool _leaf);

    void tree_walk();

    int search(int key, int& count);
    // вставка в неполный лист
    void insertNonFull(int k, int& count);
    // разделение узла на два
    void splitChild(int i, Node_b* y);
    void del(int key, int& count);
    //удаление из листа
    void removeFromLeaf(int i);
    // удаление не из листа
    void removeFromNonLeaf(int i, int& count);
    // получение предшественника
    int getPredecessor(int i);
    // получение последователя
    int getSuccessor(int i);
    // дозаполнение листа до минимального количества ключей
    void fill(int i);
    // перенос ключа из предшественника
    void borrowFromPrev(int i);
    // перенос ключа из последователя
    void borrowFromNext(int i);
    // слияние узлов
    void merge(int i);

    friend class BTree;
};

class BTree : public Tree
{
private:
    Node_b* root;
    int t;

public:
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    void tree_walk() override;
    void insertion(int key, int& count) override;
    void deletion(int key, int& count) override;
    int search(int key, int& count) override;
};