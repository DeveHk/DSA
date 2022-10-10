#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int height;
    int val;
    struct treenode* left;
    struct treenode* right;                                                                                                                                                                                                                                                                                                     
};
int getheight(struct treenode* root)
{
    if(!root)return 0;
    return root->height;    
}
struct treenode* makenode(int x)
{
    struct treenode* temp=new treenode;
    temp->val=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}
int gbf(struct treenode* root) // get_balance_factor
{
    if(!root)return 0;
    return getheight(root->left)-getheight(root->right); 
}
struct treenode* r_rotate(struct treenode* root) // right_rotate
{
    struct treenode* temp=root->left;
    struct treenode* ptr=temp->right;

    temp->right=root;
    root->left=ptr;

    root->height=max(getheight(root->left),getheight(root->right))+1;
    temp->height=max(getheight(temp->left),getheight(temp->right))+1;

    return temp;
}
struct treenode* l_rotate(struct treenode* root) // left_rotate
{
    struct treenode* temp=root->right;
    struct treenode* ptr=temp->left;

    temp->left=root;
    root->right=ptr;

    root->height=max(getheight(root->left),getheight(root->right))+1;
    temp->height=max(getheight(temp->left),getheight(temp->right))+1;

    return temp;
}
struct treenode* insert(struct treenode* root,int x)
{
    if(!root)return makenode(x);
    if(x<root->val)root->left=insert(root->left,x);
    else if(x>root->val)root->right=insert(root->right,x);
    root->height=max(getheight(root->left),getheight(root->right))+1;
    int bf=gbf(root); // balance_factor

    // left left case
    if(bf>1 && x<root->left->val) 
    return r_rotate(root);

    // right right case
    if(bf<-1 && x>root->right->val)
    return l_rotate(root);

    // left right case
    if(bf>1 && x>root->left->val)
    {root->left=l_rotate(root->left);
    return r_rotate(root);}

    // right left case
    if(bf<-1 && x<root->right->val)
    {root->right=r_rotate(root->right);
    return l_rotate(root);}

    return root; 
}
void preorder(struct treenode* root)
{
    if(!root)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct treenode* root=NULL;
    root=insert(root,4);
    root=insert(root,14);
    root=insert(root,45);
    root=insert(root,46);
    root=insert(root,49);
    root=insert(root,24);
    root=insert(root,34);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);
    preorder(root);
    return 0;
}