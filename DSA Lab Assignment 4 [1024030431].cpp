//ques 1 -> simple queue

/*#include<iostream>
using namespace std;

class SimpleQueue {
	public:
    int arr[5];
    int f;
	int b;

    SimpleQueue() { 
	f = -1; 
	b = -1; 
	}

    bool isEmpty() {
	return (f==-1); 
	}
    bool isFull() {
	return (b==4); 
	}

    void enqueue(int val) {
        if (isFull()) {
            cout<<"Queue is Full"<<endl;
            return;
        }
        if (isEmpty()) f = 0;
        arr[b++] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue is Empty"<<endl;
            return ;
        }
        cout<<"Dequeued : " <<arr[f]<<endl;
        if (f==b) f = b = -1;  // queue becomes empty
        else f++;
    }

    int peek() {
        if (isEmpty()) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    void display() {
        if (isEmpty()) {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Queue : ";
        for (int i = f; i <= b; i++)
		cout<<arr[i]<< " ";
        cout<<endl;
    }
};

int main() {
    SimpleQueue q;
    int choice;
	int val;

    while(true) {
        cout<<"Simple Queue Menu"<<endl;
        cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Peek"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"5.Exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        switch (choice) {
            case 1: cout<<"Enter value : "; 
			cin>>val; 
			q.enqueue(val); 
			break;
            case 2: q.dequeue(); 
			break;
            case 3: cout<<"Front element : "<<q.peek()<<endl; 
			break;
            case 4: q.display(); 
			break;
            case 5: return 0;
            default: cout<<"Invalid choice"<<endl;
        }
    }
}*/


//ques 2 -> circular queue

/*#include <iostream>
using namespace std;
class CircularQueue {
	public:
    int arr[5];
    int f;
	int b;
	int count;

    CircularQueue() { 
	f = 0; 
	b = -1; 
	count = 0;
	}

    bool isEmpty() { 
	return (count == 0); 
	}
    bool isFull() { 
	return (count==5); 
	}

    void enqueue(int val) {
        if (isFull()) {
            cout<<"Queue is Full"<<endl;
            return;
        }
        b = (b + 1) % 5;
        arr[b] = val;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Dequeued : "<<arr[f]<<endl;
        f = (f + 1) % 5;
        count--;
    }

    int peek() {
        if (isEmpty()) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[f];
    }

    void display() {
        if (isEmpty()) {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Queue : ";
        for (int i = 0; i < count; i++)
            cout<<arr[(f + i) % 5]<<" ";
        cout<<endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    while (true) {
        cout<<"Circular Queue Menu"<<endl;
        cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.Peek"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"5.Exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        switch (choice) {
            case 1:cout<<"Enter value : "; 
			cin>>val; 
			q.enqueue(val); 
			break;
            case 2:q.dequeue(); 
			break;
            case 3:cout<<"Front element : "<<q.peek()<<endl;
			break;
            case 4:q.display(); 
			break;
            case 5:return 0;
            default: cout<<"Invalid choice"<<endl;
        }
    }
}*/


//ques 3 -> interleave 

/*#include<iostream>
using namespace std;

class Queue {
    int arr[10];
    int front;
	int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == 9;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front++];
    }

    int size() {
        return (rear - front + 1);
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    void interleave() {
        int n = size();
        if (n % 2 != 0) {
            cout<<"Queue size must be even"<<endl;
            return;
        }

        int half = n / 2;
        int firstHalf[10];

        // Store first half
        for (int i = 0; i < half; i++) {
            firstHalf[i] = dequeue();
        }

        // Interleave
        int i = 0;
        while (i < half) {
            enqueue(firstHalf[i]);   // first half element
            enqueue(dequeue());      // second half element
            i++;
        }
    }
};

int main() {
    Queue q;
    int n, x;
    cout<<"Enter number of elements (even) : ";
    cin>>n;

    cout<<"Enter "<<n<<" elements : "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>x;
        q.enqueue(x);
    }

    cout<<"Original Queue : ";
    q.display();

    q.interleave();

    cout<<"Interleaved Queue : ";
    q.display();

    return 0;
}*/


//ques 4 -> non repeating sring

/*#include <iostream>
using namespace std;

class Queue {
    char arr[5];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == 4;
    }

    void enqueue(char val) {
        if (!isFull()) {
            arr[++rear] = val;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front++;
        }
    }

    char peek() {
        if (!isEmpty()) {
            return arr[front];
        }
        return '\0';
    }
};

void firstNonRepeating(char str[], int n) {
    Queue q;
    int freq[26] = {0};  // for 'a' to 'z' only

    for (int i = 0; i < n; i++) {
        char ch = str[i];
        int idx = ch - 'a';  // map 'a'->0, 'b'->1, etc.
        freq[idx]++;

        q.enqueue(ch);

        // remove all repeating chars from queue
        while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) {
            q.dequeue();
        }

        // print result
        if (q.isEmpty())
            cout<<-1<<" ";
        else
            cout<<q.peek()<<" ";
    }
    cout<<endl;
}

int main() {
    char str[5];
    int n;

    cout<<"Enter length of string : ";
    cin>>n;

    cout<<"Enter lowercase characters one by one:\n";
    for (int i = 0; i < n; i++) {
        cin>>str[i];
    }

    cout<<"Output: ";
    firstNonRepeating(str, n);

    return 0;
}*/


//ques 5 -> 
//part (A) -> stack using two queue


/*#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:

    bool isEmpty() {
        return q1.empty() && q2.empty();
    }

    void push(int x) {
        if (!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int element;
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            element = q1.front();
            q1.pop();
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            element = q2.front();
            q2.pop();
        }
        return element;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int element;
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            element = q1.front();
            q2.push(element);  
            q1.pop();
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            element = q2.front();
            q1.push(element);  
            q2.pop();
        }
        return element;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;    
    cout << "Pop: " << st.pop() << endl;    
    cout << "Pop: " << st.pop() << endl;    
    cout << "Pop: " << st.pop() << endl;    
    cout << "Pop: " << st.pop() << endl;    

    return 0;
}*/

//part (B) -> using one queue

/*#include<iostream>
using namespace std;

class Queue{
    int arr[50];
    int f,r,capacity;
public:
    Queue(int c=50){f=-1;r=-1;capacity=c;}
    int isEmpty(){return f==-1;}
    void enqueue(int x){
        if(r==capacity-1) return;
        if(f==-1) f=0;
        arr[++r]=x;
    }
    int dequeue(){
        if(isEmpty()) return -1;
        int x=arr[f];
        if(f==r){f=-1;r=-1;}
        else f++;
        return x;
    }
    int size(){return isEmpty()?0:r-f+1;}
};

class Stack{
    Queue q;
public:
    void push(int x){
        q.enqueue(x);
        for(int i=0;i<q.size()-1;i++) q.enqueue(q.dequeue());
    }
    void pop(){q.dequeue();}
    int top(){return q.isEmpty()?-1:q.dequeue();}
};

int main(){
    Stack s; s.push(5); s.push(15);
    cout<<s.top()<<endl;
    s.pop(); cout<<s.top()<<endl;
}*/
