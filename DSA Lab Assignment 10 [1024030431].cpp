//ques 1 ->

/*#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    unordered_set<int> s;
    for(int i = 0; i < n; i++) {
        if(s.find(nums[i]) != s.end())
            return true;
        s.insert(nums[i]);
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;

    cout << (containsDuplicate(nums, n) ? "true" : "false");
    return 0;
}*/

//ques 2 ->

/*#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int n = 4, m = 4;

    unordered_set<int> setA(A, A+n);

    cout << "Common elements: ";
    for(int i = 0; i < m; i++) {
        if(setA.find(B[i]) != setA.end())
            cout << B[i] << " ";
    }
    return 0;
}*/

//ques 3 ->

/*#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = 6;

    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++)
        freq[nums[i]]++;

    for(auto &p : freq)
        cout << p.first << " ? " << p.second << " times\n";

    return 0;
}*/

//ques 4 ->

/*#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int nums[] = {4, 5, 1, 2, 0, 4};
    int n = 6;

    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++)
        freq[nums[i]]++;

    for(int i = 0; i < n; i++) {
        if(freq[nums[i]] == 1) {
            cout << nums[i];
            return 0;
        }
    }
    return 0;
}*/

//ques 5 ->

/*#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;

    Node* curr = head;
    while(curr != NULL) {
        if(visited.find(curr) != visited.end())
            return true;
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;  // Loop back to node 2

    cout << (hasCycle(a) ? "true" : "false");
    return 0;
}*/

//ques 6 ->

/*#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = NULL; }
};

bool findDuplicates(Node* root, unordered_set<int> &seen) {
    if(root == NULL) return false;

    if(seen.find(root->data) != seen.end())
        return true;  // duplicate found

    seen.insert(root->data);

    return findDuplicates(root->left, seen) ||
           findDuplicates(root->right, seen);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(2); // Duplicate value

    unordered_set<int> seen;

    if(findDuplicates(root, seen))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}*/



