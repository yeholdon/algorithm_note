#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 35;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;
};

// preorder sequence, inoder sequence
int pre[maxn], in[maxn], n, data;
char  str[6];
stack<int> st;

Node* create(int preL, int preR, int inL, int inR) {
    if (preL > preR)
    {
        return NULL;
    }

    Node* root = new Node;
    root->data = pre[preL];

    int k = 0;
    for (k = inL; k <= inR ; k++)
    {
        if (in[k] == pre[preL])
        {
            break;
        }
    }

    int numLeft = k - inL;

    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
    
}

void postorder(Node *root) {
    if (root == NULL)
    {
        return;
    }

    postorder(root->lchild);
    postorder(root->rchild);
    static int num = 0;
    printf("%d", root->data);
    if (num != n - 1)
    {
        printf(" ");
    }
    num++;
}

int main() {
    int cnt1 = 0, cnt2 = 0;
    // inpot and get the preorder sequence, inoder sequence
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0)
        {   // input data when it is necessary
            scanf("%d", &data);
            pre[cnt1++] = data;
            st.push(data);
        }
        else
        {
            int tmp = st.top();
            in[cnt2++] = tmp;
            st.pop();
        }
        
    }

    // recreate the binaryTree
    Node* root = create(0, n - 1, 0, n - 1);
    postorder(root);
    return 0;
}