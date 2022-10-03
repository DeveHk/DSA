
//1.Balanced Tree
//2.identical Tree
//3.IsSumTree
//4.ZIGZAG traversal


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////Algorithms
//////////////////////////Complexity here is O(n), if height funtion called seprately then it could have been O(n^2)////
class Solution{
    public:
    //Q1: Function to check whether a binary tree is balanced or not.
    pair<int,int> cBalance(Node *root){
        if(root==NULL)
        return  make_pair(1,0);
        
        pair<int,int> L=cBalance(root->left),R=cBalance(root->right);
        if(L.first==1 && R.first==1)
        {
            if(abs(L.second-R.second)<=1){

                return  make_pair(1,max(L.second,R.second)+1);
            }
            else return  make_pair(0,0);
        }
        else return  make_pair(0,0);
    }
    bool isBalanced(Node *root)
    {
        return cBalance(root).first;
    }

    //Q2:  Function to check whether identical tree or not.
     bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL || r2==NULL){
            if(r1==NULL && r2==NULL)
            return 1;
            else return 0;
        }
        
        
        if(r1->data==r2->data)
        {
            return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
        }
         return 0;
    }

    //Q3: Is sum tree
    vector<int> CisSumTree(Node* root)
    {
         if(root==NULL)
         return {1,0};
         if(root->left==NULL && root->right==NULL)
         return {1,root->data};
         vector<int> L=CisSumTree(root->left), R=CisSumTree(root->right);
         return {((root->data==L[1]+R[1]) && L[0] && R[0]),2*root->data}; 
    }
    bool isSumTree(Node* root)
    {
        return CisSumTree(root)[0];
    }

    //Q4:ZIGZAG traversal
     vector <int> zigZagTraversal(Node* root)
    {
        vector<int> Result;
        if(root==NULL)
        return Result;
        queue<Node*> trav;
        trav.push(root);
        bool ltr=true;
        while(!trav.empty()){
            int Siz=trav.size();
            vector<int> ans;
            for (int i = 0; i < Siz; i++)
            {
                Node *Temp = trav.front();
                trav.pop();
                int dex=(ltr)?i:(Siz-i-1);
                ans[dex]=Temp->data;
                if (Temp->left)
                {
                    trav.push(Temp->left);
                }
                if (Temp->right)
                {
                    trav.push(Temp->right);
                }
            }

            ltr=(ltr)?false:true;
            for(auto j:ans){
                Result.push_back(j);
            }
        }
        return Result;
    }


    //Q5:Boundry traversal 
    vector<int> R;
    void printL(Node *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;
        R.push_back(root->data);
        if (root->left == NULL)
        {
            printL(root->right);
        }
        else
        {
            printL(root->left);
        }
    }
    void printLeaf(Node *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            R.push_back(root->data);
        printLeaf(root->left);
        printLeaf(root->right);
    }
    void printR(Node *root)
    {
        
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;
        
        if (root->right == NULL)
        {
            printR(root->left);
        }
        else
        {
            printR(root->right);
        }
        cout<<root->data<<" ";
        R.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        R.push_back(root->data);
        printL(root->left);
        printLeaf(root);
        printR(root->right);
        cout<<"\n";
        return R;
    }

    //Q6:
   
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// { Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends