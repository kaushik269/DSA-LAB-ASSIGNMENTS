//QUES 1 -> MENU DRIVE
 
//PART (a) -> DOUBLY LIST

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node *head = NULL;

void insertBegin() {
    int x;
    cout << "Enter value: ";
    cin >> x;
    Node *n = new Node{x, head, NULL};
    if (head != NULL) head->prev = n;
    head = n;
}

void insertEnd() {
    int x;
    cout << "Enter value: ";
    cin >> x;
    Node *n = new Node{x, NULL, NULL};
    if (!head) { head = n; return; }
    Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertAfter() {
    int val, x;
    cout << "Insert after which value? ";
    cin >> val;
    cout << "Enter value to insert: ";
    cin >> x;
    Node *t = head;
    while (t && t->data != val) t = t->next;
    if (!t) { cout << "Node not found.\n"; return; }
    Node *n = new Node{x, t->next, t};
    if (t->next) t->next->prev = n;
    t->next = n;
}

void insertBefore() {
    int val, x;
    cout << "Insert before which value? ";
    cin >> val;
    cout << "Enter value to insert: ";
    cin >> x;

    if (!head) return;
    if (head->data == val) { insertBegin(); return; }

    Node *t = head;
    while (t && t->data != val) t = t->next;
    if (!t) { cout << "Node not found.\n"; return; }

    Node *n = new Node{x, t, t->prev};
    t->prev->next = n;
    t->prev = n;
}

void deleteNode() {
    int val;
    cout << "Enter value to delete: ";
    cin >> val;
    Node *t = head;

    while (t && t->data != val) t = t->next;
    if (!t) { cout << "Node not found.\n"; return; }

    if (t->prev) t->prev->next = t->next;
    else head = t->next;

    if (t->next) t->next->prev = t->prev;

    delete t;
    cout << "Node deleted.\n";
}

void searchNode() {
    int val, pos = 1;
    cout << "Enter value to search: ";
    cin >> val;
    Node *t = head;
    while (t) {
        if (t->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        pos++;
        t = t->next;
    }
    cout << "Not found.\n";
}

void display() {
    Node *t = head;
    cout << "Doubly List: ";
    while (t) { cout << t->data << " "; t = t->next; }
    cout << endl;
}

int main() {
    int ch;
    while (true) {
        cout << "\n1.Insert Begin  2.Insert End  3.Insert After  4.Insert Before  5.Delete Node  6.Search Node  7.Display  8.Exit\n";
		cout << "Enter choice : ";
        cin >> ch;

        if (ch == 1) insertBegin();
        else if (ch == 2) insertEnd();
        else if (ch == 3) insertAfter();
        else if (ch == 4) insertBefore();
        else if (ch == 5) deleteNode();
        else if (ch == 6) searchNode();
        else if (ch == 7) display();
        else break;
    }
}*/


//PART (b) -> CIRCULAR LIST

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertBegin() {
    int x;
    cout << "Enter value: ";
    cin >> x;
    Node *n = new Node{x, NULL};

    if (!head) { head = n; n->next = head; return; }

    Node *t = head;
    while (t->next != head) t = t->next;
    n->next = head;
    t->next = n;
    head = n;
}

void insertEnd() {
    int x;
    cout << "Enter value: ";
    cin >> x;
    Node *n = new Node{x, NULL};

    if (!head) { head = n; n->next = head; return; }

    Node *t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
}

void deleteNode() {
    int val;
    cout << "Enter value to delete: ";
    cin >> val;

    if (!head) return;

    Node *t = head, *prev = NULL;

    if (head->data == val) {
        while (t->next != head) t = t->next;
        if (t == head) { delete head; head = NULL; return; }
        t->next = head->next;
        delete head;
        head = t->next;
        return;
    }

    prev = head;
    t = head->next;

    while (t != head && t->data != val) { prev = t; t = t->next; }

    if (t == head) { cout << "Not found.\n"; return; }

    prev->next = t->next;
    delete t;
}

void searchNode() {
    int val, pos = 1;
    cout << "Enter value to search: ";
    cin >> val;

    if (!head) return;
    Node *t = head;
    do {
        if (t->data == val) { cout << "Found at position " << pos << endl; return; }
        pos++; t = t->next;
    } while (t != head);
    cout << "Not found.\n";
}

void display() {
    if (!head) { cout << "Empty.\n"; return; }
    Node *t = head;
    cout << "Circular List: ";
    do { cout << t->data << " "; t = t->next; }
    while (t != head);
    cout << endl;
}


int main() {
    int ch;
    while (true) {
        cout << "\n1.Insert Begin  2.Insert End  3.Delete Node  4.Search Node  5.Display  6.Exit\n";
		cout << "Enter choice: ";
        cin >> ch;

        if (ch == 1) insertBegin();
        else if (ch == 2) insertEnd();
        else if (ch == 3) deleteNode();
        else if (ch == 4) searchNode();
        else if (ch == 5) display();
        else break;
    }
}*/


//QUES 2 -> 

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertEnd(int value) {
    Node *newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void displayWithRepeat() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    //repeat head value
    cout << head->data << endl;
}

int main() {
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);

    cout << "Output: ";
    displayWithRepeat();   

    return 0;
}*/


//QUES 3 ->

//PART (a) ->

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    if(head == NULL)
        return newNode;

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int sizeDoubly(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    cout << "Size of Doubly Linked List: " << sizeDoubly(head) << endl;
    return 0;
}*/

//PART (b) ->

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if(head == NULL) {
        newNode->next = newNode; // points to itself
        return newNode;
    }

    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return head;
}

int sizeCircular(Node* head) {
    if(head == NULL) return 0;
    
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while(temp != head);

    return count;
}

int main() {
    Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    cout << "Size of Circular Linked List: " << sizeCircular(head) << endl;
    return 0;
}*/


//QUES 4 ->

/*#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insert(char x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome() {
    if (head == NULL || head->next == NULL)
        return true;

    Node* left = head;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    for (char c : s)
        insert(c);

    if (isPalindrome())
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}*/


//QUES 5 ->

/*#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == NULL)
        return false;
    Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* head = new Node{2, NULL};
    Node* n1 = new Node{4, NULL};
    Node* n2 = new Node{6, NULL};
    Node* n3 = new Node{7, NULL};
    Node* n4 = new Node{5, NULL};

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = head;   // making the list circular

    if (isCircular(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}*/


