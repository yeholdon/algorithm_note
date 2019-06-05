#include <cstdio>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;
};

void insert(Node* &root, int x) {
    if (root == NULL)
    {
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        return;
    }

    if (root->data > x)
    {
        insert(root->lchild, x);
    }
    else // >=, right subtree
    {
        insert(root->rchild, x);
    }
    
}

void preorder(Node* root, vector<int> &vec) {
    if (root == NULL)
    {
        return;
    }
    vec.push_back(root->data);
    preorder(root->lchild, vec);
    preorder(root->rchild, vec);
}

void preorderm(Node* root, vector<int> &vec) {
    if (root == NULL)
    {
        return;
    }
    vec.push_back(root->data);
    preorderm(root->rchild, vec);
    preorderm(root->lchild, vec);
}

void postorder(Node* root, vector<int> &vec) {
    if (root == NULL)
    {
        return;
    }
    postorder(root->lchild, vec);
    postorder(root->rchild, vec);
    vec.push_back(root->data);
}

void postorderm(Node* root, vector<int> &vec) {
    if (root == NULL)
    {
        return;
    }
    postorderm(root->rchild, vec);
    postorderm(root->lchild, vec);
    vec.push_back(root->data);
}

vector<int> origin, pre, prem, post, postm;
int main() {
    int n, data;
    Node* root = NULL;
    // input
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }

    preorder(root, pre);
    preorderm(root, prem);
    postorder(root, post);
    postorderm(root, postm);

    if (origin == pre) // "==" can be used in containers
    {
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            printf("%d", post[i]);
            if (i < postm.size() - 1)
            {
                printf(" ");
            }
        }
        
    }
    else if (origin == prem) 
    {
        printf("YES\n");
        for (int i = 0; i < postm.size(); i++)
        {
            printf("%d", postm[i]);
            if (i < postm.size() - 1)
            {
                printf(" ");
            }
            
        }
        
    }
    else
    {
        printf("NO\n");
    }

    
    return 0;
}