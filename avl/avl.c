#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *right;
    struct node *left;
    int height;
} node;
int height(node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
node *create(int key)
{
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}
node *rightrotate(node *n)
{
    node *x, *y;
    x = n->left;
    y = x->right;

    x->right = n;
    n->left = y;

    n->height = max(height(n->left), height(n->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
node *leftrotate(node *n)
{
    node *x, *y;
    x = n->right;
    y = x->left;

    x->left = n;
    n->right = y;

    n->height = max(height(n->left), height(n->right));
    x->height = max(height(x->left), height(x->right));
    return x;
}
int getbalance(node *n)
{
    if (n == NULL)
        return 0;

    return height(n->left) - height(n->right);
}
node *inseart(node *n, int key)
{
    if (n == NULL)
        return create(key);

    if (key < n->key)
        n->left = inseart(n->left, key);
    else if (n->key < key)
        n->right = inseart(n->right, key);
    else
        return n;
    n->height = max(height(n->left), height(n->right)) + 1;
    int bal = getbalance(n);

    if (bal > 1 && key < n->left->key)
        return rightrotate(n);
    if (bal < -1 && key > n->right->key)
        return leftrotate(n);
    if (bal < -1 && key < n->right->key)
    {
        n->right = rightrotate(n->right);
        return leftrotate(n);
    }
    if (bal > 1 && key > n->right->key)
    {
        n->left = leftrotate(n->left);
        return rightrotate(n);
    }
    return n;
}
void print(node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->key);
    print(node->left);
    print(node->right);
}
int main()
{
    node *node = NULL;
    node = inseart(node, 12);
    node = inseart(node, 5);
    node = inseart(node, 2);
    node = inseart(node, 34);
    node = inseart(node, 15);
    print(node);
    return 0;
}