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
//making cyclic linked list
Node* makecycliclinkedlist(Node *head, Node *&tail, int pos)
{
    if(head == NULL)
    return head;
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
    if(head == NULL) return head;
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
    if(head== NULL) return head;
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
//remove the duplicates from the linked list
Node* removeduplicate(Node *head, Node *&tail)
{   
    if(head == NULL)
    {
        return head;
    }
    Node *temp= head;
    while(temp->next!=NULL)
    {
            if(temp->next->data == temp->data)
            {
                temp->next= temp->next->next;
            }
            else{
                temp= temp->next;
            }
    }
    return head;
}

//remove the duplicates from the unsorted linked list
Node* removeduplicateunsorted(Node *head, Node *&tail)
{
    if(head== NULL)
    return head;
    Node *t=NULL;
    unordered_set<int> st;
    Node *temp= head;
    while(temp!=NULL)
    {
        if(st.find(temp->data)!=st.end())
        {
            t->next= temp->next;
        }
        else{
            st.insert(temp->data);
            t= temp;
        }
        temp= temp->next;
    }
    return head;
    
}
//move the last node to first
Node* movelasttofirst(Node *head, Node *&tail)
{
    if(head == NULL) return head;
    Node *temp= head;
    while(temp->next!=tail)
    {
        temp= temp->next;
    }
    temp->next= NULL;
    tail->next= head;
    head= tail;
    tail= temp;
    return head;
}

//adding 1 to linked list
Node *addOne(Node* head, Node *&tail)
{
    if(head== NULL) return head;
    head= reverse(head, tail);
    Node *temp= head;
    int carry= 1;
    Node *t=temp;
    while(temp!=NULL || carry > 0)
    {
        int value= carry;
        if(temp!=NULL)
        {
            value += temp->data;
        }
        carry= value/10;
        value= value%10;
        if(temp!=NULL)
        {
        temp->data= value;
        }
        else
        {
            Node *newnode= new Node(value);
            t->next= newnode;
            t= newnode;
            tail= newnode;
        }
        if(temp!=NULL)
        {
        t = temp;
        temp= temp->next;
        }
    }
    head= reverse(head, tail);
    return head;
}
//middle element
int middlenode(Node *head)
{
    if(head==NULL) return -1;
    Node *fast= head, *slow= head;
    while(fast!=NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow= slow->next;
    }
    return slow->data;
}
Node * Middle(Node *head)
    {
        Node *slow,*fast;
        slow=head;
        fast=head->next;
        while( fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
Node * reverse(Node *mid)
{
        Node *curr,*prev,*nextnode;
        curr=mid;
        prev=NULL;
        while(curr!=NULL)
        {
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
}
bool isPalindrome(Node *head)
{
        //Your code here
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        Node *temp;
        Node *mid=Middle(head);
        temp=mid->next;
        mid->next=reverse(temp);
        Node *head1=head;
        Node *head2=mid->next;
        
        while(head2!=NULL)
        {
            if(head2->data!=head1->data)
            {
                return false;
            }
            head2=head2->next;
            head1=head1->next;
        }
        return true;
}
Node* deletefromcircularelinkedlist(Node *head, int key)
{
    Node *temp=head;
    Node *t= temp;
    while(temp->next!=head)
    {
        if(temp->data== key)
        {
            t->next= temp->next;
            free(temp);
            break;
        }
        else{
            t= temp;
            temp= temp->next;
        }    
    }
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
    cout<<"8. to remove the duplicate from sorted linked list: "<<endl;
    cout<<"9. to remove the duplicate from the unsorted linked list: "<<endl;
    cout<<"10. to move the last node to first pos: "<<endl;
    cout<<"11. to add 1 in  linked list: "<<endl;
    cout<<"12. to find the middle element of linked list: "<<endl;
    cout<<"13. to find the linked list is palindrome or not: "<<endl;
    cout<<"14. to delete from the circular linked list: "<<endl;
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
    case 8:
        head= removeduplicate(head, tail);
        display(head);
        break;
    case 9:
        head= removeduplicateunsorted(head, tail);
        display(head);
        break;
    case 10:
        head= movelasttofirst(head, tail);
        display(head);
        break;
    case 11:
        head= addOne(head, tail);
        display(head);
        break;
    case 12:
        {
            int middle= middlenode(head);
            if(middle== -1)
            cout<<"middle element not found"<<endl;
            else
            cout<<"Middle element of the linked list: "<<middle<<endl;
            break;
        }
    case 13:{
        bool check = isPalindrome(head);
        if(check)
        cout<<"Linked list is palindrome."<<endl;
        else cout<<"Linked list is not a palindrome."<<endl;
    }
    case 14:
    {
        int key=4;
        Node *temp= head;
        while(temp->next!=head)
        {
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        head= deletefromcircularelinkedlist(head, key);
        break;

    }
    default: 
        cout<<"Please enter a valid option!!"<<endl;
        break;
    }
    }
    return 0;
}
