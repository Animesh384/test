#include<stdio.h>
#include<stdlib.h>
typedef struct anode{
    int val;
    struct anode* left;
    struct anode* right;
    int height;
} anode;
int height(anode* node){
    if(node==NULL)
    return 0;
    return node->height;
}
int getbalance(anode* node){
    return(height(node->left)-height(node->right));
}
int max(int a,int b){
    return a>b?a:b;
}
anode* newnode(int key){
    anode* node=(anode*)malloc(sizeof(anode));
    node->val=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}
anode* rightrotate(anode* node){
    anode* x=node->left;
    anode* t2=x->right;
    x->right=node;
    node->left=t2;

    node->height=max(height(node->left),height(node->right))+1;
    x->height=max(height(node->left),height(node->right))+1;
    return x;
}

anode* leftrotate(anode* node){
    anode* y=node->right;
    anode* t2=y->left;
    y->left=node;
    node->right=t2;

    node->height=max(height(node->left),height(node->right))+1;
    y->height=max(height(node->left),height(node->right))+1;
    return y;
}
anode* insert(anode* node,int key){
    if(node==NULL){
        return (newnode(key));    
    }
    if(key < node->val){
        node->left=insert(node->left,key);
    }
    else if(key>node->val){
        node->right=insert(node->right,key);
    }
    else
    return node;
    node->height=max(height(node->left),height(node->right))+1;
    int balance=getbalance(node);


    if(balance>1&&key<node->left->val){
        return rightrotate(node);
    }
    if(balance>-1&&key>node->right->val){
         return leftrotate(node);
    }
    if(balance>1&&key>node->left->val){
        node->left=leftrotate(node->left);
        return  rightrotate(node);
    }
    if(balance>-1&&key<node->left->val){
        node->left=rightrotate(node->left);
        return  leftrotate(node);
    }
    return node;
}
void preoder(anode* node){
    if(node==NULL)
    return ;
    printf("%d  ",node->val);
    preoder(node->left);
    preoder(node->right);
}
int main(){
    anode* root=NULL;
    root=insert(root,1);
    preoder(root);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    preoder(root);
}