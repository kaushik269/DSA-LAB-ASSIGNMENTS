//ques 1 -> menu drive program

/*#include <iostream>
using namespace std;
int stack[5];
int top=-1;

int isEmpty() {
    if(top==-1)
        return 1;   // true
    else
        return 0;   // false
}

int isFull() {
    if(top==4)
        return 1;   // true
    else
        return 0;   // false
}

void push(int value) {
    if(isFull()) {
        cout<<"Stack Overflow! Cannot push "<<value<<endl;
    }
	 else{
        top++;
        stack[top]=value;
        cout<<value<<" pushed into stack"<<endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout<<"Stack Underflow! Nothing to pop"<<endl;
    } 
	else{
        cout<<stack[top]<<" popped from stack"<<endl;
        top--;
    }
}

void peek() { 
    if(isEmpty()) {
        cout<<"Stack is empty. No top element"<<endl;
    } 
	else {
        cout<<"Top element is : "<<stack[top]<<endl;
    }
}

void display() {
    if (isEmpty()) {
        cout<<"Stack is empty"<<endl;
    } 
	else{
        cout<<"Stack elements (top to bottom) : ";
        for(int i=top; i>=0; i--) {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int choice;
	int value;

    while(1) {
        cout<<"STACK MENU"<<endl;;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.isEmpty"<<endl;
        cout<<"4.isFull"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Peek"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        if(choice==1) {
            cout<<"Enter value to push : ";
            cin>>value;
            push(value);
        } 
        else if(choice==2) {
            pop();
        } 
        else if (choice==3) {
            if (isEmpty())
                cout<<"Stack is Empty"<<endl;
            else
                cout<<"Stack is not Empty"<<endl;
        } 
        else if (choice==4) {
            if (isFull())
                cout<<"Stack is Full"<<endl;
            else
                cout<<"Stack is not Full"<<endl;
        } 
        else if (choice==5) {
            display();
        } 
        else if (choice==6) {
            peek();
        } 
        else if (choice==7) {
            cout<<"Exiting program"<<endl;
            break;
        } 
        else {
            cout<<"Invalid choice!"<<endl;
        }
    }
    return 0;
}*/


//ques 2 -> stack reverse

/*#include<iostream>
#include<string>
using namespace std;
char stack[20];
int top=-1;

void push(char c) {
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

int main(){
    string str;
    cout<<"Enter string : ";
    getline(cin, str);   

    for(int i=0; i<str.length(); i++) {
        push(str[i]);
    }

    cout<<"Reversed string is : ";
    while(top!=-1) {
        cout<<pop();
    }
    return 0;
}*/


//ques 3 -> balanced brackets

/*#include<iostream>
using namespace std;
#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { 
	top = -1;
	}
	
    bool isEmpty() { 
	return top == -1;
	}

    bool isFull() { 
	return top == MAX - 1; 
	}

    void push(char val) {
        if (isFull()) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = val;
    }

    char pop() {
        if (isEmpty()) {
            return -1; // return null char if empty
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }
};

bool isBalanced(string expr) {
    Stack s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false; // nothing to match

            char top = s.pop();

            // check correct matching
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // expression is balanced only if stack is empty
    return s.isEmpty();
}

int main() {
    string expr;
    cout<<"Enter an expression : ";
    cin>>expr;

    if (isBalanced(expr))
        cout<<"Balanced Parentheses"<<endl;
    else
        cout<<"Not Balanced"<<endl;
    return 0;
}*/


//ques 4 -> infix to postfix 

/*#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { 
	top = -1; 
	}

    bool isEmpty() { 
	return top == -1; 
	}

    bool isFull() {
	return top == MAX - 1; 
	}

    void push(char val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

// precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return -1;
}

// check if operand (letter or digit)
bool isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z') || 
        (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

string infixToPostfix(string expr) {
    Stack s;
    string result = "";

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (isOperand(ch)) {
            result += ch;  // operand ? output
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }
            s.pop(); // remove '('
        }
        else { // operator
            while (!s.isEmpty() && precedence(ch) <= precedence(s.peek())) {
                result += s.pop();
            }
            s.push(ch);
        }
    }

    // pop remaining operators
    while (!s.isEmpty()) {
        result += s.pop();
    }

    return result;
}

int main() {
    string expr;
    cout<<"Enter infix expression : ";
    cin>>expr;

    cout<<"Postfix expression : "<<infixToPostfix(expr)<<endl;
    return 0;
}*/


//ques 5 -> postfix eval

/*#include<iostream>
#include<stack>
#include<string>
using namespace std;
int solve(int val1, int val2, int ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
int main(){
    string s = "26+4*8/3-"; // postfix expression
    // we need only one stack for values
    stack<int>val;
    for(int i=0;i<s.length();i++){
        // check if s[i] is digit (0-9)
        if(s[i]>=48 && s[i]<=57){ // digit
            val.push(s[i]-48);
        }
        else{ // s[i] it is -> *,/,+,-
            // work
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<"26+4*8/3- gives : "<<val.top()<<endl; // 1
    return 0;
}*/
