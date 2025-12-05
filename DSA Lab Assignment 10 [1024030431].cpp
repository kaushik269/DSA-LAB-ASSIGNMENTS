//ques 1 -> 
/*#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,2,3,1};
    unordered_set<int> s;
    for(int x: nums){
        if(s.count(x)){
            cout << "true";
            return 0;
        }
        s.insert(x);
    }
    cout << "false";
}*/

//ques 2->

/*#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5,6};
    unordered_set<int> s(A.begin(), A.end());
    for(int x: B){
        if(s.count(x)) cout << x << " ";
    }
}*/

//ques 3->

/*#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {2,3,2,4,3,2};
    unordered_map<int,int> m;
    for(int x: nums) m[x]++;
    for(auto &p: m) cout << p.first << " -> " << p.second << " times\n";
}*/

//ques 4->

/*#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {4,5,1,2,0,4};
    unordered_map<int,int> m;
    for(int x: nums) m[x]++;
    for(int x: nums){
        if(m[x] == 1){
            cout << x;
            break;
        }
    }
}*/

//ques 5->

/*#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){data=d; next=NULL;}
};

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->next=b; b->next=c; c->next=d; d->next=b;

    unordered_set<Node*> s;
    Node* curr = a;
    while(curr){
        if(s.count(curr)){
            cout << "true";
            return 0;
        }
        s.insert(curr);
        curr = curr->next;
    }
    cout << "false";
}*/

//ques 6->


/*#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d){data=d; left=right=NULL;}
};

bool dfs(Node* root, unordered_set<int> &s){
    if(!root) return false;
    if(s.count(root->data)) return true;
    s.insert(root->data);
    return dfs(root->left,s) || dfs(root->right,s);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->right->left = new Node(5);

    unordered_set<int> s;
    if(dfs(root,s)) cout << "Duplicates Found";
    else cout << "No Duplicates";
}*/





