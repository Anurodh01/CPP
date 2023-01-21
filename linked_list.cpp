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
//to display a linked list
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

//reverse a linked list
Node* reverse(Node *head, Node *&tail)
{
    Node *current= head, *prev= NULL, *nextnode= NULL;
    while(current!= NULL)
    {
        nextnode= current->next;
        current->next= prev;
        prev= current;
        current= nextnode;
    }
    return prev;
}
//making cyclic linked list
Node* makecycliclinkedlist(Node *head, Node *&tail, int pos)
{
    Node *temp= head;
    int i=1;
    while(i<pos)
    {
        temp= temp->next;
        i++;
    }
    tail->next= temp;
    return head;
}
//to detect the loop in linked list // returning pair so that we might know
// the is cycle is there or not and at what position fast and slow pointer meet 
pair<bool, Node*> detectloop(Node *head, Node *&tail)
{
    Node *fast= head;
    Node *slow= head;
    while(fast!= NULL && fast->next!= NULL)
    {
        fast= fast->next->next;
        slow= slow->next;
        if(fast== slow)
        {
            return {true, slow};
        }
    }
    return {false, NULL};
}
//to find the position where the cycle of linked list start
Node* cycleposition(Node *head, Node *&tail)
{
    pair<bool, Node*> p= detectloop(head, tail);
    if(p.first)
    {
        Node *slow= p.second;
        Node *temp= head;
        while(temp!= slow)
        {
            temp= temp->next;
            slow= slow->next;
        }
        return slow;
    }
    return NULL;
}
//to remove the  cycle in linked list
Node* removecycle(Node *head, Node *&tail)
{
    //starting pos of cycle
    Node *startingpos= cycleposition(head, tail);
    Node *temp= startingpos;
    while(temp->next!= startingpos)
    {
        temp= temp->next;
    }
    temp->next= NULL;
    tail= temp;
    return head;
}
int main()
{
    Node *head= NULL;
    int choice;
    Node *tail= head;
    
    while(true)
    {
    cout<<"\n1. Create linked list: "<<endl;
    cout<<"2. Reverse linked list: "<<endl;
    cout<<"3. display linked list: "<<endl;
    cout<<"4. to make cyclic linked list: "<<endl;
    cout<<"5. to detect whether the cycle present in linked list or not :"<<endl;
    cout<<"6. to find the starting point of cycle: "<<endl;
    cout<<"7. to remove the cycle from the linked list :"<<endl;
    cout<<"0. to exit"<<endl;
    cout<<"\n enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 0:
        exit(0);
    case 1: 
        head= linkedlist(head, tail);
        break;
    case 2:
        head= reverse(head, tail);
        break;
    case 3: 
        display(head);
        break;
    case 4:
        cout<<"Enter the position to where you want to join the last node link: "<<endl;
        int nodeposition;
        cin>>nodeposition;
        head= makecycliclinkedlist(head, tail, nodeposition);
        break;
    case 5:
        if(detectloop(head,tail).first)
        cout<<"Linked list contains cycle. "<<endl;
        else
        cout<<"Cycle is not present in linked list. "<<endl;
        break; 
    case 6:
        {
        Node *nodepos= cycleposition(head,tail);
        if(nodepos== NULL)
        cout<<"cycle is not present"<<endl;
        else cout<<"starting pos of the cycle of linked list is: "<<nodepos->data<<endl;
        break;
        }
    case 7:
        head= removecycle(head, tail);
        break;
    default: 
        cout<<"Please enter a valid option!!"<<endl;
        break;
    }
    }
    return 0;
}
