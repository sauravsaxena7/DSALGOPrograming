//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
Node* stk1[10000];
Node* stk2[10000];

int top1=-1;
int top2=-1;

int size1=0;
int size2=0;


void push(Node* node, int &sizee, int &top, Node* stk[]){

    if(top==-1){
        top=0;
        stk[top]=node;
        
    }else{
        top=top+1;
        stk[top]=node;
    }
    sizee++;
}



Node* pop(int &sizee, int &top, Node* stk[]){
    Node* node;

    if(top==0){

        node=stk[top];
        top=-1;

    }else{
       node=stk[top];
       top=top-1; 
    }
    sizee--;
   
    return node;
}


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
        vector<int> res;
        

        top1=-1;
        top2=-1;
        size1=0;
        size2=0;



        push(root,size1,top1,stk1);

       

        while(size1!=0 || size2!=0){



           while(size1!=0){
            Node* node = pop(size1,top1,stk1);
            res.push_back(node->data);
            if(node->left!=NULL){
                push(node->left,size2,top2,stk2);
            }

            if(node->right!=NULL){
                push(node->right,size2,top2,stk2);
            }
           }


           while(size2!=0){
            Node* node = pop(size2,top2,stk2);
            res.push_back(node->data);
            if(node->right!=NULL){
                push(node->right,size1,top1,stk1);
            }

             if(node->left!=NULL){

                push(node->left,size1,top1,stk1);
            }
           }

        }




        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends

//7 9 7 8 8 6 N 10 9