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
            parent->rightchild = newnode;
        }
    }

    void search(string element, node*& parent, node*& currentnode)
    {
        currentnode = ROOT;
        parent = NULL;
        while ((currentnode !=NULL) &&(currentnode->info !=element))
        {
            parent = currentnode;
            if (element < currentnode->info)
                currentnode = currentnode->leftchild;
            else
                currentnode = currentnode->rightchild;
        }
    }

    void inorder(node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info <<" ";
        
            
        }
    }
};