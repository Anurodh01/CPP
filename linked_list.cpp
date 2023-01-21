#include<bits/stdc++.h>
using namespace std;
//node 
class Node
{
    public:
    int data;
    Node *next;

    //constructor to initialize the node
    Node(int data)
    {
        this->data= data;
        this->next= NULL;
    }
};

// to create the linked list
Node* linkedlist(Node *head, Node *&tail)
{
    while(true)
    {
    cout<<"Enter the data to insert in linked list: -1 to exit "<<endl;
    int data;
    cin>>data;
    if(data == -1)
    {
        break;
    }
    Node *newnode= new Node(data);
    if(head== NULL)
    {
        head= tail= newnode;
    }
    else{
        tail->next= newnode;
        tail= newnode;
    }
    }
    return head;
}
void display(Node *head)
{
    Node *temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL\n";
}
int main()
{
    Node *head= NULL;
    Node *tail= head;
    head= linkedlist(head, tail);
    display(head);
    return 0;
}
