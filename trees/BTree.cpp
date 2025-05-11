#include "BTree.h"

Node_b::Node_b(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
    data = new int[2 * t - 1];
    C = new Node_b * [2 * t];
    n = 0;
}

// поиск ключа
int Node_b::search(int key, int& count) {
    int i = 0;
    while (i < n && key > data[i]) {
        i++;
        count++;
    }
    count++;
    if (data[i] == key) {
        count++;
        return 1;
    }
    count++;
    if (leaf == true) return 0;
    return C[i]->search(key, count);
}

// удаление ключа
void Node_b::del(int key, int& count) {
    int i = 0;
    while (i < n && data[i] < key) {
        i++;
        count++;
    }
    if (i < n && data[i] == key) {
        if (leaf == true) removeFromLeaf(i);
        else removeFromNonLeaf(i, count);
    }
    else {
        if (leaf != true) {
            bool per;
            if (i == n) per = true;
            else per = false;
            if (C[i]->n < t) fill(i);
            if (per && i > n) C[i - 1]->del(key, count);
            else C[i]->del(key, count);
        }
    }
    count++;
}

//удаление из листа
void Node_b::removeFromLeaf(int i) {
    for (int ind = i + 1; ind < n; ind++) {
        data[ind - 1] = data[ind];
    }
    n--;
}

//удаление не из листа
void Node_b::removeFromNonLeaf(int i, int& count) {
    int k = data[i];
    if (C[i]->n >= t) {
        int pred = getPredecessor(i);
        data[i] = pred;
        C[i]->del(pred, count);
    }
    else if (C[i + 1]->n >= t) {
        int succ = getSuccessor(i);
        data[i] = succ;
        C[i + 1]->del(succ, count);
    }
    else {
        merge(i);
        C[i]->del(k, count);
    }
}

// получение предшественника
int Node_b::getPredecessor(int i) {
    Node_b* cur = C[i];
    while (cur->leaf == false) cur = cur->C[cur->n];
    return cur->data[cur->n - 1];
}

// получение последователя
int Node_b::getSuccessor(int i) {
    Node_b* cur = C[i + 1];
    while (cur->leaf == false) cur = cur->C[0];
    return cur->data[0];
}

// дозаполнение листа до минимального количества ключей
void Node_b::fill(int i) {
    if (i != 0 && C[i - 1]->n >= t) borrowFromPrev(i);
    else if (i != n && C[i + 1]->n >= t) borrowFromNext(i);
    else {
        if (i != n) merge(i);
        else merge(i - 1);
    }
}

// перенос ключа из предшественника
void Node_b::borrowFromPrev(int i) {
    Node_b* child = C[i];
    Node_b* sibling = C[i - 1];
    for (int j = child->n - 1; j >= 0; j--) {
        child->data[j + 1] = child->data[j];
    }
    if (child->leaf != true) {
        for (int j = child->n; j >= 0; j--) {
            child->C[j + 1] = child->C[j];
        }
    }
    child->data[0] = data[i - 1];
    if (child->leaf != true) {
        child->C[0] = sibling->C[sibling->n];
    }
    data[i - 1] = sibling->data[sibling->n - 1];
    child->n += 1;
    sibling->n -= 1;
}

// перенос ключа из последователя
void Node_b::borrowFromNext(int i) {
    Node_b* child = C[i];
    Node_b* sibling = C[i + 1];
    child->data[(child->n)] = data[i];
    if (child->leaf != true) {
        child->C[(child->n) + 1] = sibling->C[0];
    }
    data[i] = sibling->data[0];
    for (int j = 1; j < sibling->n; j++) {
        sibling->data[j - 1] = sibling->data[j];
    }
    if (sibling->leaf != true) {
        for (int j = 1; j <= sibling->n; j++) {
            sibling->C[j - 1] = sibling->C[j];
        }
    }
    child->n += 1;
    sibling->n -= 1;
}

// слияние узлов
void Node_b::merge(int i) {
    Node_b* child = C[i];
    Node_b* sibling = C[i + 1];
    child->data[t - 1] = data[i];
    for (int j = 0; j < sibling->n; j++) {
        child->data[j + t] = sibling->data[j];
    }
    if (child->leaf != true) {
        for (int j = 0; j <= sibling->n; j++) {
            child->C[j + t] = sibling->C[j];
        }
    }
    for (int j = i + 1; j < n; j++) {
        data[j - 1] = data[j];
    }
    for (int j = i + 2; j <= n; j++) {
        C[j - 1] = C[j];
    }
    child->n += sibling->n + 1;
    n--;
    delete (sibling);
}

//вставка ключа
void BTree::insertion(int key, int& count) {
    if (root == NULL) {
        root = new Node_b(t, true);
        root->data[0] = key;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            Node_b* s = new Node_b(t, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->data[0] < key) i++;
            s->C[i]->insertNonFull(key, count);
            root = s;
        }
        else root->insertNonFull(key, count);
    }
}

// вставка в неполный лист
void Node_b::insertNonFull(int key, int&count) {
    int i = n - 1;
    if (leaf == true) {
        while (i >= 0 && data[i] > key) {
            data[i + 1] = data[i];
            i--;
            count++;
        }
        count++;
        data[i + 1] = key;
        n++;
    }
    else {
        while (i >= 0 && data[i] > key) {
            count++;
            i--;
        }
        count++;
        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);

            if (data[i + 1] < key) i++;
        }
        C[i + 1]->insertNonFull(key, count);
    }
}

// разделение узла на два новых
void Node_b::splitChild(int i, Node_b* x) {
    Node_b* temp = new Node_b(x->t, x->leaf);
    temp->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        temp->data[j] = x->data[j + t];
    }
    if (x->leaf == false) {
        for (int j = 0; j < t; j++) {
            temp->C[j] = x->C[j + t];
        }
    }
    x->n = t - 1;
    for (int j = n; j >= i + 1; j--) {
        C[j + 1] = C[j];
    }
    C[i + 1] = temp;
    for (int j = n - 1; j >= i; j--) {
        data[j + 1] = data[j];
    }
    data[i] = x->data[t - 1];
    n++;
}

//центрированный обход
void Node_b::tree_walk() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false) C[i]->tree_walk();
    }
    if (leaf == false) C[i]->tree_walk();
}

//удаление ключа
void BTree::deletion(int key, int& count){
    if (root != NULL) {
        root->del(key, count);
        if (root->n == 0) {
            Node_b* tmp = root;
            if (root->leaf == true) root = NULL;
            else root = root->C[0];
            delete tmp;
        }
    }
}

// поиск ключа
int BTree::search(int key, int& count) {
    if (root != NULL) {
        int res = root->search(key, count);
        return res;
    }
    else return 0;
}

// функция вызова операции центрированного обхода
void BTree::tree_walk() {
    if (root != NULL)
        root->tree_walk();
}