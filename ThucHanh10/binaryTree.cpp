#include<iostream>
#include<queue>
#include<cmath>
#include <climits>

using namespace std;

struct tNode
{
    int data;
    tNode *left;
    tNode *right;
};

tNode* newNode(int value)
{
    tNode* node = new tNode;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// thêm 1 node có giá trị value làm con của node p
void insertNode(tNode* p, int value)
{
    tNode* node = newNode(value);
    node->data = value;
    if (p->left == NULL)
    {
        p->left = node;
    }
    else if (p->right == NULL)
    {
        p->right = node;
    }
    else {
        node->left = p->left;
        p->left = node;
    }
}

tNode* buildTree(int a[], int i, int n)
{
    if (i >= n)
    {
        return NULL;
    }

    tNode* node = newNode(a[i]);
    node->left = buildTree(a, 2*i + 1, n);
    node->right = buildTree(a, 2*i + 2, n);
    return node;
}

void preOrder(tNode* node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(tNode* node)
{
    if (node == NULL)
    {
        return;
    }

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(tNode* node)
{
    if (node == NULL)
    {
        return;
    }

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void levelOrder(tNode* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<tNode*> q;
    q.push(root);
    
    int level = 1, idx = 0;  // xử lý output
    while (!q.empty())
    {
        tNode* curNode = q.front();
        q.pop();
        cout << curNode->data << " ";

        idx++;
        if (idx == pow(2, level) - 1)
        {
            cout << endl;
            level++;
        }

        if (curNode->left != NULL)
        {
            q.push(curNode->left);
        }

        if (curNode->right != NULL)
        {
            q.push(curNode->right);
        }
    }
}

// kiểm tra xem có phải cây nhị phân tìm kiếm không
bool isBST(tNode* node, int min_val, int max_val) 
{
    min_val = INT_MIN;
    max_val = INT_MAX;

    if (node == NULL) 
    {
        return true;
    }

    if (node->data < min_val || node->data > max_val) 
    {
        return false;
    }

    return isBST(node->left, min_val, node->data - 1) &&
           isBST(node->right, node->data + 1, max_val);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    tNode* root = new tNode;
    root = buildTree(a, 0, n);

    levelOrder(root);

    return 0;
}