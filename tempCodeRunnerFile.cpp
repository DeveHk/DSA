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
