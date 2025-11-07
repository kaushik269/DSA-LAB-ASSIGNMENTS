//ques 1 -> traversals 

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void preorder(node* root) {
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(node* root) {
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main() {
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}*/


//ques 2 ->

//part (a) -> search 
//recursive approach

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else root->right=insertNode(root->right,val);
    return root;
}

node* searchRec(node* root,int key) {
    if(root==NULL || root->val==key) return root;
    if(key<root->val) return searchRec(root->left,key);
    return searchRec(root->right,key);
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,1);
    insertNode(root,6);

    if(searchRec(root,6)) cout<<"Found";
    else cout<<"Not Found";
}*/

//non recursive approach

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else root->right=insertNode(root->right,val);
    return root;
}

node* searchNonRec(node* root,int key) {
    while(root!=NULL && root->val!=key) {
        if(key<root->val) root=root->left;
        else root=root->right;
    }
    return root;
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,1);
    insertNode(root,6);

    if(searchNonRec(root,6)) cout<<"Found";
    else cout<<"Not Found";
}*/

//part (b) -> maximum 

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else root->right=insertNode(root->right,val);
    return root;
}

node* findMax(node* root) {
    while(root->right!=NULL) root=root->right;
    return root;
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,1);
    insertNode(root,6);

    cout<<findMax(root)->val;
}*/

//part (c) -> minimum

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else root->right=insertNode(root->right,val);
    return root;
}

node* findMin(node* root) {
    while(root->left!=NULL) root=root->left;
    return root;
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,1);
    insertNode(root,6);

    cout<<findMin(root)->val;
}*/

//part (d) -> inorder successor

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else root->right=insertNode(root->right,val);
    return root;
}

node* findMin(node* root) {
    while(root->left!=NULL) root=root->left;
    return root;
}

node* successor(node* root,int key) {
    node* curr=root;
    node* succ=NULL;
    while(curr!=NULL) {
        if(key<curr->val) {
            succ=curr;
            curr=curr->left;
        } else curr=curr->right;
    }
    return succ;
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,1);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);

    node* s=successor(root,6);
    if(s) cout<<s->val;
    else cout<<"None";
}*/

//part (e) -> In-order Predecessor

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else root->right=insertNode(root->right,val);
    return root;
}

node* findMax(node* root) {
    while(root->right!=NULL) root=root->right;
    return root;
}

node* predecessor(node* root,int key) {
    node* curr=root;
    node* pred=NULL;
    while(curr!=NULL) {
        if(key>curr->val) {
            pred=curr;
            curr=curr->right;
        } else curr=curr->left;
    }
    return pred;
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,1);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);

    node* p=predecessor(root,6);
    if(p) cout<<p->val;
    else cout<<"None";
}*/


//ques 3 -> 

//part (a) -> Insert an element (no duplicates are allowed)

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else if(val>root->val) root->right=insertNode(root->right,val);
    return root;
}

void inorder(node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,3);
    insertNode(root,6);
    inorder(root);
}*/

//part (b) -> Delete an existing element

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else if(val>root->val) root->right=insertNode(root->right,val);
    return root;
}

node* findMin(node* root) {
    while(root->left!=NULL) root=root->left;
    return root;
}

node* deleteNode(node* root,int key) {
    if(root==NULL) return root;
    if(key<root->val) root->left=deleteNode(root->left,key);
    else if(key>root->val) root->right=deleteNode(root->right,key);
    else {
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        node* temp=findMin(root->right);
        root->val=temp->val;
        root->right=deleteNode(root->right,temp->val);
    }
    return root;
}

void inorder(node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,6);
    inorder(root);
    cout<<endl;
    root=deleteNode(root,6);
    inorder(root);
}*/

//part (c) -> Maximum Depth of BST

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else if(val>root->val) root->right=insertNode(root->right,val);
    return root;
}

int maxDepth(node* root) {
    if(root==NULL) return 0;
    int a=maxDepth(root->left);
    int b=maxDepth(root->right);
    return (a>b?a:b)+1;
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,6);
    insertNode(root,7);
    cout<<maxDepth(root);
}*/

//part (d) -> Minimum Depth of BST

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else if(val>root->val) root->right=insertNode(root->right,val);
    return root;
}

int minDepth(node* root) {
    if(root==NULL) return 0;
    int a=minDepth(root->left);
    int b=minDepth(root->right);
    if(a==0) return b+1;
    if(b==0) return a+1;
    return (a<b?a:b)+1;
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,6);
    cout<<minDepth(root);
}*/


//ques 4 ->  Write a program to determine whether a given binary tree is a BST or not. 

/*#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;
    node(int val) {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertNode(node* root,int val) {
    if(root==NULL) return new node(val);
    if(val<root->val) root->left=insertNode(root->left,val);
    else if(val>root->val) root->right=insertNode(root->right,val);
    return root;
}

bool isBSTUtil(node* root,int minv,int maxv) {
    if(root==NULL) return true;
    if(root->val<=minv || root->val>=maxv) return false;
    return isBSTUtil(root->left,minv,root->val) && isBSTUtil(root->right,root->val,maxv);
}

bool isBST(node* root) {
    return isBSTUtil(root,-1000000000,1000000000);
}

int main() {
    node* root=NULL;
    root=insertNode(root,8);
    insertNode(root,3);
    insertNode(root,10);
    insertNode(root,1);
    insertNode(root,6);

    if(isBST(root)) cout<<"BST";
    else cout<<"Not BST";
}*/







