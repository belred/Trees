#include "AVLTree.h"

// возвращает высоту вершины
int AVLTree::height(avltree t) {
    if (t != NULL) return t->height;
    else return 0;
}

// определяет высоту поддерева
void AVLTree::fix_height(avltree t) {
    int l_h = height(t->left);
    int r_h = height(t->right);
    if (l_h > r_h) t->height = l_h + 1;
    else t->height = r_h + 1;
}

// разность высот правого и левого поддеревьев
int AVLTree::balance_right_left(avltree t) {
    return height(t->right) - height(t->left);
}

// правый поворот вокруг t
avltree AVLTree::rotate_right(avltree t) {
    avltree temp = t->left;
    t->left = temp->right;
    temp->right = t;
    fix_height(t);
    fix_height(temp);
    return temp;
}

// левый поворот вокруг t
avltree AVLTree::rotate_left(avltree t) {
    avltree temp = t->right;
    t->right = temp->left;
    temp->left = t;
    fix_height(t);
    fix_height(temp);
    return temp;
}

// балансировка t
avltree AVLTree::balance(avltree t) {
    fix_height(t);
    if (balance_right_left(t) == 2) {
        // большой левый поворот
        if (balance_right_left(t->right) < 0) {
            t->right = rotate_right(t->right);
        }
        // малый левый поворот
        return rotate_left(t);
    }
    if (balance_right_left(t) == -2) {
         //большой правый поворот
        if (balance_right_left(t->left) > 0) {
            t->left = rotate_left(t->left);
        }
        //малый правый поворот
        return rotate_right(t);
    }
    return t;
}

// вставка ключа
avltree AVLTree::insert(avltree t, int key, int& count) {
    if (t == NULL) {
        avltree temp = new Node_avl();
        temp->data = key;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        return temp;
    }
    if (key < t->data) {
        count++;
        t->left = insert(t->left, key, count);
    }
    else {
        count++;
        t->right = insert(t->right, key, count);
    }
    return balance(t);
}

// поиск ключа
int AVLTree::search_tree(avltree t, int key, int& count) {
    if (t == NULL) return 0;
    else if (t->data == key) {
        count++;
        return 1;
    }
    else if (key < t->data) {
        count++;
        return search_tree(t->left, key, count);
    }
    else if (key > t->data) {
        count++;
        return search_tree(t->right, key, count);
    }
}

// удаление ключа
void AVLTree::delete_tr(avltree& t1, avltree t, avltree& temp) {
    //удаляем самую правую вершину левого поддерева
    if (t1->right != NULL) delete_tr(t1->right, t, temp);
    //ставим элементы со смещением после удаления
    else {
        temp = t1;
        t->data = t1->data;
        t1 = t1->left;
    }
}

void AVLTree::del_tree(avltree& t, int key, int& count) {
    avltree temp;
    temp = NULL;
    if (t != NULL) {
        if (key > t->data) {
            count++;
            del_tree(t->right, key, count);
        }
        else if (key < t->data) {
            count++;
            del_tree(t->left, key, count);
        }
        else {
            count++;
            temp = t;
            if (t->right == NULL) t = t->left;
            else if (t->left == NULL) t = t->right;
            else delete_tr(t->left, t, temp);
            delete temp;
        }
    }
    if (t != NULL) t = balance(t);
}

// центрированный обход
void AVLTree::tree_walk(avltree node) {
    if (node != NULL) {
        tree_walk(node->left);
        tree_walk(node->right);
    }
}

void  AVLTree::insertion(int key, int& count) { this->root = insert(this->root, key, count); }

void AVLTree::deletion(int key, int& count) { del_tree(this->root, key, count); }

int AVLTree::search(int key, int& count) { return search_tree(this->root, key, count); }

void AVLTree::tree_walk() { tree_walk(this->root); }