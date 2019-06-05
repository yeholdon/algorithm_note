#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int height;
    Node* lchild;
    Node* rchild;
};

Node *newNode(int x) {
    Node* root = new Node;
    root->data = x;
    root->height = 1;
    root->lchild = root->rchild = NULL;
    return root;
}

int getHeight(Node* root) {
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}

void updataHeight(Node* root) {
    root->height =  max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(Node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(Node* &root) {
    Node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updataHeight(root);
    updataHeight(tmp);
    root = tmp;
}

void R(Node* &root) {
    Node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updataHeight(root);
    updataHeight(tmp);
    root = tmp;
}

void insert(Node* &root, int x) {
    if (root == NULL)
    {
        root = newNode(x);
        return;
    }

    if (x < root->data)
    {
        insert(root->lchild, x);
        updataHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                // LL
                R(root);
            }
            else if (getBalanceFactor(root->lchild) == -1) {
                // LR
                L(root->lchild);
                R(root);
            }
            
        }

        
        
    }
    else
    {
        insert(root->rchild, x);
        updataHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1)
            {
                // RR
                L(root);
            }
            else if (getBalanceFactor(root->rchild) == 1)
            {
                // RL
                R(root->rchild);
                L(root);
            }
        
        }
    }
    

    
}

Node* create(int data[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}

int main() {
    int n, data[25];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    
    Node* root = create(data, n);
    printf("%d\n", root->data);
    return 0;
}