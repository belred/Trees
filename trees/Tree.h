#pragma once

//абстрактный класс
class Tree
{
	virtual void insertion(int k, int& count);

    virtual void deletion(int k, int& count);

    virtual int search(int k, int& count);

    virtual void tree_walk();
};

