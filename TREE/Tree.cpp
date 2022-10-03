#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int Data;
    node* left;
    node* right;
//this is a pointer to active class object
    node(int d){
        this->Data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//Algorithm 1:   Level order create
/*Here We used a que to implement the task, First Root entered in the que, then its children asked and entered in Q (root pops), this goes on */
node* CreateTreeLevel(node* root){
    
    queue<node*> q;

    cout<<"Enter Value for Root: ";
    int root_Data;
    cin>>root_Data;
    root=new node(root_Data);
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if(!q.empty()){
            q.push(NULL);
            cout << endl;}
        }
        else
        {
            cout << "Enter value left to " << temp->Data << ": ";
            cin >> root_Data;
            if (root_Data != -1)
            {
                temp->left = new node(root_Data);
                q.push(temp->left);
            }

            cout << "Enter value right to " << temp->Data << ": ";
            cin >> root_Data;
            if (root_Data != -1)
            {
                temp->right = new node(root_Data);
                q.push(temp->right);
            }
        }
    }
    return root;
}

//Algorithm 2:   Post Order  Recursive LRRo tree creation
node* createTree(node* root){
    cout<<"\n DATA: ";
    int data;
    cin>>data;
    if(data==-1){
        return root;
    }
    root= new node(data);
    cout<<"Left of "<<data;
    root->left=createTree(root->left);
    cout<<"Right of "<<data;
    root->right=createTree(root->right);
}

//Algorithm 3:   Level order print
/*Here We used a que to implement the task, elements enterd in Q at every level and then their children inserted and they themself deleted*/
void printTreeLevel(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * temp=q.front();
        q.pop();
        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
                cout<<"\n";
            }
        }
        else{
            cout<<temp->Data<< "   ";
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
            
        }
    }
}

//Algorithm 4:   Tree Prints
//part ((a)): PostOrder
node* Postprint(node* root)
{
    if(root==NULL)
    return root;

    Postprint(root->left);//L
    Postprint(root->right);//R
    cout<<" "<<root->Data;//Root
}
//part ((b)): PreOrder
node* Preprint(node* root)
{
    if(root==NULL)
    return root;

    cout<<" "<<root->Data;//Root
    Preprint(root->left);//L
    Preprint(root->right);//R
    
}
//part ((c)): InOrder
node* Inprint(node* root)
{
    if(root==NULL)
    return root;
    
    Inprint(root->left);//L
    cout<<" "<<root->Data;//Root
    Inprint(root->right);//R
    
}
// Algorithm 5: creating BST
node *insT(node *root, int dat)
{
    if (root->Data > dat)
    {
        if (root->left == NULL)
        {
            root->left = new node(dat);
            return root;
        }
        insT(root->left, dat);
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new node(dat);
            return root;
        }
        insT(root->right, dat);
    }
}
node *CreateBST(node *root)
{
    cout << "Root: ";
    int dat;
    cin >> dat;
    root = new node(dat);
    while (dat != -1)
    {
        cout << "enter nxt value: ";
        cin>>dat;
        if(dat!=-1)
        insT(root,dat);
    }
    return root;
}
//Algorithm 6: finding in BST
node *find(node *root, int dat)
{
    if((root==NULL) || (root->Data==dat));
    return root;

    if (root->Data > dat)
    {
        insT(root->left, dat);
    }
    else if(root->Data < dat)
    {
        insT(root->right, dat);
    }
}
void finder(node * root){
    cout<<"\nELEMENT TO FIND: ";
    int dat;
    cin>>dat;
    if(find(root,dat)){
        cout<<"PRESENT";
    }
    else{
        cout<<"NOT PRESENT";
    }
}


int main(){
    node *Tree=CreateBST(Tree);
    printTreeLevel(Tree);
    finder(Tree);
}