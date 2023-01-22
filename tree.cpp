#include<bits/stdc++.h>
using namespace std;
class Node
{   
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data= data;
        this->left= NULL;
        this->right= NULL;
    }
};

Node* createbinarytree(Node *root)
{
    int data;
    cout<<"Enter the data (-1 to exit): "<<endl;
    cin>>data;
    if(data== -1)
    {
        return NULL;
    }
    root= new Node(data);
    cout<<"Enter the data to insert in left of the "<<root->data<<": ";
    root->left= createbinarytree(root->left);
    cout<<"Enter the data to insert in the right of the "<<root->data<<": ";
    root->right= createbinarytree(root->right);
    return root;
}
void inorder(Node *root)
{
    if(root== NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(root== NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//level order traversal
void levelorder(Node *root)
{
    if(root == NULL)
    return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *frontnode= q.front();
        q.pop();
        if(frontnode== NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
        cout<<frontnode->data<<" ";
        if(frontnode->left)
        q.push(frontnode->left);
        if(frontnode->right)
        q.push(frontnode->right);
        }
    } 
}


//for the reverse order traversal
//like 
//    1
//  2   3
//then 1: 2 3
// 0: 1
//output: 2 3 1
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int>  result;
    if(root == NULL)
    return result;
    map<int, vector<int>, greater<int> > mp;
    queue<pair<int, Node*>> q;
    q.push(make_pair(0,root));
    while(!q.empty())
    {
        pair<int, Node*> frontnode= q.front();
        q.pop();
        Node *node= frontnode.second;
        int level= frontnode.first;
        mp[level].push_back(node->data);
        if(node->left)
        q.push(make_pair(level+1, node->left));
        if(node->right)
        q.push(make_pair(level+1, node->right));
    }
    for(auto i: mp)
    {
        for(auto j: i.second)
        result.push_back(j);
    }
    return result;
}
int height(Node *root)
{
    if(root== NULL)
    return 0;
    int left= height(root->left);
    int right= height(root->right);
    int h= max(left, right)+1;
    return h;
}
int main()
{
    Node *root= NULL;
    while(true)
    {
        int choice;
        cout<<"\n1. To create the binary tree: "<<endl;
        cout<<"2. To print the preorder traversal: "<<endl;
        cout<<"3. To print the inorder traversal: "<<endl;
        cout<<"4. To print the postorder traversal: "<<endl;
        cout<<"5. To print the level order traversal: "<<endl;
        cout<<"6. To print the reverse level order traversal: "<<endl;
        cout<<"7. To get the height of tree: "<<endl;
        cout<<"0 to exit"<<endl;
        cout<<"enter the choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1: 
            root = createbinarytree(root);
            break;
        case 2:
            cout<<"Preorder traversal:" <<endl;
            preorder(root);
            break;
        case 3:
            cout<<"\nInorder Traversal: "<<endl;
            inorder(root);
            break;
        case 4:
            cout<<"\nPostorder Traversal :"<<endl;
            postorder(root);
            break;
        case 5:
            cout<<"\nLevel Order Traversal :"<<endl;
            levelorder(root);
            break;
        case 6:
        {
            vector<int> ans= reverseLevelOrder(root);
            for(auto I : ans)
            cout<<I<<" ";
            cout<<endl;
            break;
        }
        case 7:
        {
            int h= height(root);
            cout<<"height of tree is : "<<h<<endl;
            break;
        }
        case 0:
            exit(0);
        default:
            cout<<"please enter the right choice."<<endl;
        }
    }  
}


///tree :   1 2 4 -1 5 -1 -1 3 -1 -1 7 8 -1 -1 9 -1 -1 