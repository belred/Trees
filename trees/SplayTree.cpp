#include "SplayTree.h"

//����� ����� � ������
//spltree SplayTree::search_tree(spltree node, int key, int& count) {
//    if (node == NULL || node->data == key) {
//        count++;
//        return node;
//    }
//    count++;
//    if (key < node->data) {
//        count++;
//        if (node->left != NULL)
//            return search_tree(node->left, key, count);
//        else return node;
//    }
//    else {
//        count++;
//        if (node->right != NULL)
//            return search_tree(node->right, key, count);
//        else return node;
//    }
//}

spltree SplayTree::search_tree(spltree node, int key, int& count) {
    if (node == NULL || node->data == key) {
        count++;
        return node;
    }
    while (node != NULL && node->data != key) {
        count++;
        while (key < node->data) {
            count++;
            if (node->left != NULL)
                node = node->left;
            else return node;
        }
        count++;
        if (node->data != key) {
            while (key > node->data) {
                count++;
                if (node->right != NULL)
                    node = node->right;
                else return node;
            }
            count++;
        }
        count++;
    }
    count++;
    return node;
}

// ����� ������� ������ t
void SplayTree::leftRotate(spltree t) {
    spltree temp = t->right;
    t->right = temp->left;
    if (temp->left != NULL) temp->left->parent = t;
    temp->parent = t->parent;
    if (t->parent == NULL) this->root = temp;
    else if (t == t->parent->left) t->parent->left = temp;
    else t->parent->right = temp;
    temp->left = t;
    t->parent = temp;
}

// ������ ������� ������ t
void SplayTree::rightRotate(spltree t) {
    spltree temp = t->left;
    t->left = temp->right;
    if (temp->right != NULL) temp->right->parent = t;
    temp->parent = t->parent;
    if (t->parent == NULL) this->root = temp;
    else if (t == t->parent->right) t->parent->right = temp;
    else t->parent->left = temp;
    temp->right = t;
    t->parent = temp;
}

//����������� ������� � ������ ������
void SplayTree::splay(spltree t) {
    while (t->parent != NULL) {
        if (t->parent->parent == NULL) {
            if (t == t->parent->left) {
                // ������� zig ������
                rightRotate(t->parent);
            }
            else {
                // ������� zig �����
                leftRotate(t->parent);
            }
        }
        else if (t == t->parent->left && t->parent == t->parent->parent->left) {
            // ������� zig-zig
            rightRotate(t->parent->parent);
            rightRotate(t->parent);
        }
        else if (t == t->parent->right && t->parent == t->parent->parent->right) {
            // ������� zag-zag
            leftRotate(t->parent->parent);
            leftRotate(t->parent);
        }
        else if (t == t->parent->right && t->parent == t->parent->parent->left) {
            // ������ zig-zag
            leftRotate(t->parent);
            rightRotate(t->parent);
        }
        else {
            // ������� zag-zig
            rightRotate(t->parent);
            leftRotate(t->parent);
        }
    }
}

//����� ������������� �������� � ���������
spltree SplayTree::maximum(spltree node) {
    while (node->right != NULL) node = node->right;
    return node;
}

//������� ���� �����������
spltree SplayTree::join(spltree s1, spltree s2) {
    if (s1 == NULL) return s2;
    if (s2 == NULL) return s1;
    spltree x = maximum(s1);
    splay(x);
    x->right = s2;
    s2->parent = x;
    return x;
}

//�������������� �����
void SplayTree::tree_walk(spltree node) {
    if (node != NULL) {
        tree_walk(node->left);
        tree_walk(node->right);
    }
}

//�������� �������
void SplayTree::delete_tree(int key, int& count) {
    spltree x = NULL;
    x = join(root->left, root->right);
    root = x;
}

//������� ������ �������� ��������������� ������
void SplayTree::tree_walk() { tree_walk(this->root); }

//����� ����� � ������ � ������������ ��� � ������ ������
int SplayTree::search(int key, int& count) {
    spltree x = search_tree(root, key, count);
    if (x) {
        splay(x);
        if (x->data == key)
            return 1;
        else return 0;
    }
    else return 0;
}

//������� ������ �������� �������� �������
void SplayTree::deletion(int data, int& count) { delete_tree(data, count); }

//������� ������� � ������
void  SplayTree::insertion(int key, int& count) {
    spltree node = new Node_spl;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->data = key;
    spltree x = root;
    if (root == NULL) {
        root = node;
    }
    else {
        if (node->data < x->data) {
            node->right = x;
            node->left = x->left;
            x->left = NULL;
            if (node->left != NULL)
                node->left->parent = node;
        }
        else {
            node->left = x;
            node->right = x->right;
            x->right = NULL;
            if (node->right != NULL)
                node->right->parent = node;
        }
        root->parent = node;
        root = node;
    }
}