#include<bits/stdc++.h>
using namespace std;
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

void insertatend(Node *&head, Node *&tail, int value)
{
    Node *newnode= new Node(value);
    if(head== NULL)
    {
        head= tail= newnode;
    }
    else{
        tail->next= newnode;
        tail= newnode;
    }
}

Node* reverse(Node *head, Node *&tail)
{
    if(head== NULL) return head;
    Node *current= head, *prev= NULL, *nextnode= NULL;
    while(current!= NULL)
    {
        nextnode= current->next;
        current->next= prev;
        prev= current;
        current= nextnode;
    }
    tail= head;
    return prev;
}

Node* addtwolinkedlist(Node *head1,Node *tail1, Node *head2, Node *tail2)
{

    Node *dummyhead=NULL;
    Node *dummytail= dummyhead;
    if(head1== NULL)
    return head2;
    if(head2 == NULL)
    return head1;
    head1= reverse(head1, tail1);
    // display(head1);
    head2= reverse(head2, tail2);
    // display(head2);
    Node *temp1= head1; Node *temp2= head2;
    int carry=0;
    while((temp1!=NULL || temp2!=NULL) || carry > 0)
    {
        int value= carry;
        if(temp1!=NULL)
        value += temp1->data;
        if(temp2!=NULL)
        value += temp2->data;
        carry= value/10;
        value= value%10;
        insertatend(dummyhead, dummytail, value);
        // cout<<dummyhead->data<<" ";
        if(temp1!=NULL)
        temp1= temp1->next;
        if(temp2!=NULL)
        temp2= temp2->next;
    }
    dummyhead= reverse(dummyhead, dummytail);
    return dummyhead;
}

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int, int> mp;
    Node *temp= head1;
    while(temp!=NULL)
    {
        mp[temp->data]++;
        temp= temp->next;
    }
    Node *head = NULL;
    Node *tail= head;
    temp= head2;
    while(temp!=NULL)
    {
        if(mp.find(temp->data)!= mp.end())
        {
            Node* newnode= new Node(temp->data);
            if(head== NULL)
            head= tail = newnode;
            else
            {
                tail->next= newnode;
                tail= newnode;
            }
            if(mp[temp->data]==1)
            mp.erase(temp->data);
            else
            mp[temp->data]--;
            temp= temp->next;
        }
        else{
            temp= temp->next;
        }
    }
    return head;
    
}

int main()
{
    Node *head1=NULL, *head2=NULL;
    Node *tail1= head1;
    cout<<"Create the first linked list:"<<endl;
    head1= linkedlist(head1, tail1);
    Node *tail2= head2;
    cout<<"Create the second linked list:"<<endl;
    head2= linkedlist(head2, tail2);
    Node *head=NULL;
    Node *tail= head; 
    while(true)
    {
     int choice;
    cout<<"1.The addition of two linked list:"<<endl;
    cout<<"2.Intersection of two linked list:"<<endl;
    cout<<"0.to exit "<<endl;
    cout<<"enter choice:"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        head= addtwolinkedlist(head1 ,tail1, head2, tail2);
        display(head);
        break;
    case 2:
        head= findIntersection(head1,head2);
        display(head);
        break;
    case 0:
        exit(0);
    default: 
        cout<<"Please choose the right option."<<endl;
    }
    }
}