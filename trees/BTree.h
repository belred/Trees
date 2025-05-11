#pragma once
#include <iostream>
#include "Tree.h"

using namespace std;

// ��������� ���� � �������� ��� ���
class Node_b {
private:
    int* data; //������ ��������
    int t; //������� �������� t
    Node_b** C; //�������
    int n; //���������� ������
    bool leaf; //����

public:
    Node_b(int _t, bool _leaf);

    void tree_walk();

    int search(int key, int& count);
    // ������� � �������� ����
    void insertNonFull(int k, int& count);
    // ���������� ���� �� ���
    void splitChild(int i, Node_b* y);
    void del(int key, int& count);
    //�������� �� �����
    void removeFromLeaf(int i);
    // �������� �� �� �����
    void removeFromNonLeaf(int i, int& count);
    // ��������� ���������������
    int getPredecessor(int i);
    // ��������� �������������
    int getSuccessor(int i);
    // ������������ ����� �� ������������ ���������� ������
    void fill(int i);
    // ������� ����� �� ���������������
    void borrowFromPrev(int i);
    // ������� ����� �� �������������
    void borrowFromNext(int i);
    // ������� �����
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