//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
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
class Solution {
  public:
    void findTarget(Node* root, int target, Node* &tar){
        if(root==NULL) return;
        
        findTarget(root->left, target, tar);
        if(root->data==target) {
            tar = root;return;
        }
        findTarget(root->right, target, tar);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        //step 1: find the Node* for target
        Node* tar;
        findTarget(root, target, tar);
        
        
        //step 2: mark parents
        unordered_map<Node*, Node*> par;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr->left){
                par[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                par[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        vector<int> vis(10005, 0);
        
        //step 3: find the total time
        int tot = 0;
        q.push(tar);
        // if(par.find(tar)!=par.end()) q.push(par[tar]);
        // if(tar->left) q.push(tar->left);
        // if(tar->right) q.push(tar->right);
        
        while(!q.empty()){
            int sz = q.size();
            bool ok = false;
            for(int i=0;i<sz;i++){
               
                auto curr = q.front();
                vis[curr->data] = 1;
                q.pop();
                if(par.find(curr)!=par.end() && vis[par[curr]->data]==0) {
                    q.push(par[curr]);
                    ok = true;
                }
                if(curr->left && vis[curr->left->data]==0) {
                    q.push(curr->left);
                    ok = true;
                }
                if(curr->right && vis[curr->right->data]==0) {
                    q.push(curr->right);
                    ok = true;
                }
                
            }
            if(ok) tot++;
        }
    return tot;
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends