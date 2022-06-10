#include<iostream>
using namespace std;

/*
Unit 2

[1] Stacks:
a) They are a type of data structure which isnt already avaialable in the c++ language thus we make it using class.
b) It is of type First-In:Last-Out or Last-In:First-Out
c) Traversing in a stack isnt free like arrays, you can only access the top most element here.

[2] Operations available:
a)Push: To insert an element from the top
b)Pop: To remove the top most element 
c)Top: To access the top most element
d)isEmpty: To check if the stack is empty
e)size: Returns the size of the stack

[3] Stack using arrays:

a)Most basic:
*/
#define MAX 100

class basic_stack{
    int a[MAX];
    int top;

    public:
    basic_stack(){
        top=-1;
    }
    void push(int element){
        a[++top]=element;
    }
    void pop(){
        if (top!=-1)
        {
            top--;
        }
        else{
            return;
        }
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return size()==0;
    }
};


// b)Stack with no maximum limit or bound of element count:  

class unlimited_stack{
    int*a;
    int top;
    int capacity=2;

    public:
    unlimited_stack(){
        a=new int[2];
        top=-1;
    }
    void push(int element){
        if (top+1==capacity)
        {
            int* new_data=new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                new_data[i]=a[i];
            }
            delete[]a;
            a=new_data;
            capacity*=2;
        }
        a[++top]=element;
    }
    void pop(){
        if (top==-1)
        {
            return;
        }
        top--;
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return size()==0;
    }
};

//[4] Using templates

template <typename T>
class stacks_using_template{
    T* a;
    int top;
    int capacity=2;

    public:
    stacks_using_template(){
        a=new T[2];
        top=-1;
    void push(T element){
        if (top+1==capacity)
        {
            T* new_data=new T[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                new_data[i]=a[i];
            }
            delete[]a;
            a=new_data;
            capacity*=2;
        }
        a[++top]=element;
    }
    void pop(){
        if (top==-1)
        {
            return;
        }
        top--;
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return size()==0;
    }
    }
}

//[5] By default stack module:
#include<stack>
//Note this stack uses templates so for making a object we make it like:
stack<int> s1;

//[6] Using linked list:

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class stack_using_LL{
    Node* head;
    int top=-1;
    public:
    stack_using_LL(){
        head=NULL;
    }
    int getSize(){
        return top+1;
    }
    bool isEmpty(){
        if (top!=-1)
        {
            return false;
        }
        else{
            return true;
        }
    }
    //here we add in the opposite way i.e. from the head location
    void push(int element){
        Node* new_node=new Node(element);
        new_node->next=head;
        head=new_node;
        top++;
    }
    int pop(){
        if(top!=-1){
            Node*temp=head;
            head=head->next;
            top--;
            return temp->data;
        }
        if(top==-1){
            return -1;
        }
    }
    int top(){
        if(top!=-1){
            return head->data;
        }
        else{return -1;}
    }
};

//questions_on_stacks
//q1. For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
//q2. You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
/*q3. Tower of Hanoi: 
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks   and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3. No disk may be placed on top of a smaller disk.
*/

/*
[2] Tower of Hanoi
*/
void TOH(int n, int A , int B, int C){
    if (n>0)
    {
        TOH(n-1,A,C,B);//moving n-1 discs from A to B using C as helper
        cout<<"Move a disc from "<<A<<" to "<<C<<endl;
        TOH(n-1,B,A,C);//moving n-1 discs from B to C using A
    }
    return;
}

//[3] Queues: 
