#include <iostream>
#include <string>
using namespace std;

class node
{
    public:
    string info;
    node* leftchild;
    node* rightchild;


    node(string i, node* l, node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }

};

class binarytree
{
public:
    node* ROOT;
    binarytree()
    {
        ROOT = nullptr; 
    }
    void insert(string element)
    {
        node* newnode = new node(element, nullptr, nullptr);
        newnode->info = element;
        newnode->leftchild =nullptr;
        newnode->rightchild = nullptr;

        node* parent = nullptr;
        node* currentnode = nullptr;
        search(element, parent, currentnode);

        if (parent == nullptr)
        {
            ROOT = newnode;
            return;
        }

        if (element < parent ->info)
        {
            parent->leftchild = newnode;
        }
        else if (element > parent->info)
        {
            
        }

    }
};