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
            inorder(ptr->rightchild);          
        }
    }

    void preorder(node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info <<" ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);          
        }
    }

    void postorder(node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);          
            cout << ptr->info <<" ";
        }
    }
};

int main()
{
    binarytree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1.implement insert operation" << endl;
        cout << "2.implement inorder operation" << endl;
        cout << "3.implement preorder operation" << endl;
        cout << "4.implement postorder operation" << endl;
        cout << "EXIT" << endl;
        cout << "\nEnter your choice (1-5) : ";
        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word ;
            x.insert (word);
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        }
    }
}