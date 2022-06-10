/*
1. Singly Linked list

a) A linked list is a self made data structure where we have the address of the first member called head, and every element stores the address of next element thus there is no problem of size limit.
b)The last element points to next and every element is known as a Node
c)Every node has 2 data in the class, that is: int data(to store data of the node) and Node* next (to store address of next element)

Why use?
1. No limit of size
2. Non continous data and descrete data

Disadvantages:
1. Can only move forward in linked list and not backwards.
2. No indexing thus have to traverse everytime to reach at a location.
*/

//CODE:

//[1] Creating a LL:
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

//[2] Code for printing a LL:

//using iteration
void printf(Node* head){
    while(head!=NULL){
        cout<<head->data<<",";
        head=head->next;
    }
    cout<<endl;
    return;
}

//using recursion
void print(Node* head){
    //base
    if (head==NULL)
    {
        return;
    }
    //induction
    cout<<head->data<<",";
    print(head->next);
}

//[3] Code for taking input:

Node* input(){
    int d=0;
    Node* head=NULL;
    Node* tail=NULL;
    while(d!=-1){
        cin>>d;
        if(d==-1){
            return head;
        }
        if(head==NULL){
            head=new Node(d);
            tail=head; 
        }
        else{
            Node* new_head=new Node(d);
            tail->next=new_head;
            tail=tail->next;
        }
    }
    return head;
}

//[4] Delete at nth position:

//iterative
/*
When we wanna delete, we are basically just shifting the next variable of the prev node to the next node, thus here we need to access both the prev node, current node to delete and the next node's address thus we traverse till the n-1th pos as in singly LL we cant go back.
*/

int length(Node* head){
    int cnt=0;
    while (head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

Node* deleting_iterative(Node* head, int n){
    //base cases
    if (head==NULL)
    {
        return head;
    }
    if(n>length(head)-1){
        return head;
    }
    if (n==0)
    {
        head=head->next;
        return head;
    }
    
    //traverse
    Node* temp=head;
    for (int i = 0; i < n-1; i++)
    {
        temp=temp->next;
    }

    //address shiftings
    Node*t=temp->next;
    temp->next=t->next;
    return head;
}

Node* deleting_recursive(Node* head, int n){
    //base case
    if(head==NULL){
        return head;
    }
    if (n>length(head)-1)
    {
        return head;
    }
    if (n==0)
    {
        head=head->next;
        return head;
    }

    //induction
    Node*x=deleting_recursive(head->next,n-1);
    head->next=x;
    return head; 
}

//[5] Inserting at nth pos:

Node* inserting_iterative(Node* head, int n, int data){
    Node* new_node = new Node(data);
    if (head==NULL)
    {
        head=new_node;
        return head;
    }
    if (n>length(head))
    {
        return head;
    }
    if(n==0){
        Node*temp=head->next;
        head=new_node;
        new_node->next=temp;
    }

    //iteration
    Node*temp=head;
    for (int i = 0; i < n-1; i++)
    {
        temp=temp->next;
    }

    //manipulation of address
    Node*t=temp->next;
    temp->next=new_node;
    new_node->next=t;
    return head;
}

Node* inserting_recursive(Node* head, int n, int data){
    Node* new_node = new Node(data);
    if (head==NULL)
    {
        head=new_node;
        return head;
    }
    if (n>length(head))
    {
        return head;
    }
    //base
    if(n==0){
        Node*temp=head->next;
        head=new_node;
        new_node->next=temp;
    }

    //induction
    Node*x=inserting_recursive(head->next,n-1,data);
    head->next=x;
    return head;
}

//Problems on singly Linked list

//q1. You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise
//q2. You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
//q3. You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
//q4. You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
// To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.
//q5. You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

