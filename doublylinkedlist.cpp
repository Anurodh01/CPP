#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data= data;
        this->next= NULL;
        this->prev= NULL;
    }
};
Node* createdoublylinkedlist(Node *head, Node *&tail)
{
    while(true)
    {
    cout<<"Enter the data you want to insert into the linked list: "<<endl;
    int data;
    cin>>data;
    if(data== -1)
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
        newnode->prev= tail;
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
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node *reverse(Node *head)
{
    Node *temp = head;
    Node *t= NULL;
    while(temp!=NULL)
    {
       temp->prev= temp->next;
       temp->next= t;
       t= temp;
       temp= temp->prev;
    }
    return t;
}
void pairwithgivensum(Node *head, Node *tail, vector<vector<int>> &result, int sum)
{
    //using the two pointer approach
    Node *startnode= head;
    Node *endnode= tail;
    while(startnode!=endnode)
    {
        if((startnode->data+endnode->data) == sum)
        {
            vector<int> ans;
            ans.push_back(startnode->data);
            ans.push_back(endnode->data);
            result.push_back(ans);
            startnode= startnode->next;
        }
        else if((startnode->data+endnode->data)> sum)
        {
            endnode= endnode->prev;
            // cout<<endnode->data<<endl;
        }
        else startnode= startnode->next;
    }
}
int main()
{
    Node *head=NULL;
    Node *tail= head;
    head= createdoublylinkedlist(head, tail);
    display(head);
    // head= reverse(head);
    // display(head);
    cout<<"Pairs with the given sum in doubly linked list: "<<endl;
    vector<vector<int>> result;
    int sum=7;
    pairwithgivensum(head, tail, result, sum);
    for(auto I: result)
    {
        cout<<"{";
        for(auto J: I)
        cout<<J<<", ";
        cout<<"},";
    }
}