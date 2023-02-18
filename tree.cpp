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
    map<int, vector<int>, greater<int> > mp;   //this will store the value of higher key first
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

Node* mirror(Node *root, Node *newroot)
{
    if(root == NULL)
    return NULL;

    newroot= new Node(root->data);
    newroot->right= mirror(root->left, newroot->right);
    newroot->left= mirror(root->right, newroot->left);
    return newroot;
}
//returning the diameter and height of the node at the same time to reduce tthe time complexity
pair<int, int> diameter(Node *root)
{
    if(root== NULL)
    {
        pair<int,int> p(0,0);
        return p;
    }
    pair<int, int> left= diameter(root->left);
    pair<int, int> right= diameter(root->right);
    int op1= left.first;
    int op2= right.first;
    int op3= left.second+ right.second+1;
    int maxi= max(max(op1, op2),op3);
    int h= max(left.second, right.second)+1;
    return {maxi, h};
}

//to print the left view of the tree
vector<int> leftviewoftree(Node *root)
{
    vector<int> result;
    if(root== NULL)
    return result;
    queue<pair<int, Node*> > q;
    map<int, int> mp;
    q.push(make_pair(0,root));
    while(!q.empty())
    {
        pair<int, Node*> frontnode= q.front();
        q.pop();
        int level= frontnode.first;
        Node *node= frontnode.second;
        if(mp.find(level)==mp.end())
        {
            mp[level]= node->data;
        }
        if(node->left)
        q.push(make_pair(level+1, node->left));
        if(node->right)
        q.push(make_pair(level+1, node->right));
    }
    for(auto i:mp)
    {
        result.push_back(i.second);
    }
    return result;
}
vector<int> rightviewoftree(Node *root)
{
    vector<int> result;
    if(root== NULL)
    return result;
    queue<pair<int, Node*>> q;
    map<int, int> mp;
    q.push(make_pair(0,root));
    while(!q.empty())
    {
        pair<int , Node*> frontnode= q.front();
        q.pop();
        int level= frontnode.first;
        Node *node= frontnode.second;
        mp[level]= node->data;
        if(node->left)
        q.push(make_pair(level+1, node->left));
        if(node->right)
        q.push(make_pair(level+1, node->right));
    }
    for(auto i: mp)
    result.push_back(i.second);

    return result;
}

vector<int> topviewoftree(Node *root)
{
    vector<int> result;
    if(root== NULL)
    return result;
    queue<pair<int, Node*>> q;   //for queue<pair<horizontal_distance, node>> q;
    map<int,int> mp;    //to store the result at each hd
    q.push(make_pair(0,root));
    while(!q.empty())
    {
        pair<int, Node*> frontnode= q.front();
        q.pop();
        int hd= frontnode.first;
        Node *node= frontnode.second;
        if(mp.find(hd)==mp.end())
        {
            mp[hd]= node->data;
        }
        if(node->left)
        q.push(make_pair(hd-1, node->left));
        if(node->right)
        q.push(make_pair(hd+1, node->right));
    }
    for(auto i: mp)
    result.push_back(i.second);

    return result;
}

vector<int> bottomviewoftree(Node *root)
{
    vector<int> result;
    if(root== NULL)
    return result;
    queue<pair<int, Node*>> q;   //for queue<pair<horizontal_distance, node>> q;
    map<int,int> mp;    //to store the result at each hd
    q.push(make_pair(0,root));
    while(!q.empty())
    {
        pair<int, Node*> frontnode= q.front();
        q.pop();
        int hd= frontnode.first;
        Node *node= frontnode.second;
        mp[hd]= node->data;
        if(node->left)
        q.push(make_pair(hd-1, node->left));
        if(node->right)
        q.push(make_pair(hd+1, node->right));
    }
    for(auto i: mp)
    result.push_back(i.second);

    return result;
}

vector<int> zigzagtraversal(Node *root)
{
    vector<int> result;
    if(root== NULL)
    return result;
    stack<Node*> currentlevel;
    stack<Node*> nextlevel;
    bool lefttoright= true;
    currentlevel.push(root);
    while(!currentlevel.empty())
    {
        Node *frontnode= currentlevel.top();
        result.push_back(frontnode->data);
        currentlevel.pop();
        if(lefttoright)
        {
            if(frontnode->left)
            nextlevel.push(frontnode->left);
            if(frontnode->right)
            nextlevel.push(frontnode->right);
        }
        else{
            if(frontnode->right)
            nextlevel.push(frontnode->right);
            if(frontnode->left)
            nextlevel.push(frontnode->left);
        }
        if(currentlevel.empty())
        {
            swap(currentlevel, nextlevel);
            lefttoright= !lefttoright;
        }
    }
    
return result;
}

vector<vector<int>> zigzagtraversalwithvector(Node *root)
{
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    bool flag= false;    //flag is represent if flag is true means we have to put the things in left to right if false right to left
    while(!q.empty())
    {
        int size= q.size();
        vector<int> answer;
        while(size--)
        {
            Node *node= q.front();
            q.pop();
            answer.push_back(node->data);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        flag= !flag;
        if(flag== false)
        reverse(answer.begin(), answer.end());
        result.push_back(answer);
    }
    return result;
} 
pair<bool,int> isbalanced(Node *root)
{
    if(root== NULL)
    {
        pair<bool, int> p(true, 0);
        return p;
    }
    pair<bool, int> lefttree = isbalanced(root->left);
    pair<bool, int> righttree= isbalanced(root->right);
    bool balancecondition = abs(lefttree.second - righttree.second) <=1;
    pair<bool, int> ans;
    ans.first= false;
    ans.second= max(lefttree.second, righttree.second)+1;
    if(lefttree.first && righttree.first && balancecondition)
    {
        ans.first= true;
    }
    return ans;
   
}

void diagonaltraversal(Node *root, vector<vector<int>> &result)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size= q.size();
        vector<int> answer;
        while(size--)
        {
            Node *temp= q.front();
            q.pop();    
            while(temp)
            {
                answer.push_back(temp->data);
                if(temp->left)
                {
                    q.push(temp->left);
                }
                temp= temp->right;
            }
        }
        result.push_back(answer);
    }
}

Node* treetolist(Node *root)
{
    Node *current= root;
   
    while(current!=NULL)
    {
    Node *temp;
    if(current->left)
    temp= current->left;
    else
    current= current->right;

    //now finding the inorder predecessor of the node
    while(temp->right!=NULL && temp!=current)
    {
        temp = temp->right;
    }
    if(temp->right==NULL)
    {
        temp->right= current->right;
        current->right= current->left;
        current->left= NULL;
        current= current->right;
        
    }
    }
    return root;
}

void displaylist(Node *head)
{
    Node *temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->right;
    }
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
        cout<<"8. To get the mirror image of the binary tree:" <<endl;
        cout<<"9. To find the diameter of the binary tree:"<<endl;
        cout<<"10. To find the leftview of the binary tree:"<<endl;
        cout<<"11. To find the rightview of the binary tree:"<<endl;
        cout<<"12. To find the topview of the binary tree:"<<endl;
        cout<<"13. To find the bottomview of binary tree: "<<endl;
        cout<<"14. to find the zigzag traversal of the binary tree: "<<endl;
        cout<<"15. To check whether the binary tree is balanced tree or not: "<<endl;
        cout<<"16. To get the diagonal traversal of binary tree: "<<endl;
        cout<<"17. to convert the binary tree to singly linked list: "<<endl;
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
        case 8:
            {
                Node *mirror_root= NULL;
                mirror_root= mirror(root, mirror_root);
                cout<<"\n Inorder traversal of real tree:"<<endl;
                inorder(root);
                cout<<"\n Inorder traversal of mirror tree:"<<endl;
                inorder(mirror_root);
                break;
            }
        case 9:
            {
                cout<<"the diameter of the binary tree is: "<<diameter(root).first<<endl;
                break;
            }
        case 10:
        {
                vector<int> output;
                output = leftviewoftree(root);
                cout<<"Left view of tree:"<<endl;
                for(auto i: output)
                cout<<i<<" "; 
                break;
        }
        case 11:
        {
                vector<int> output;
                output = rightviewoftree(root);
                cout<<"Left view of tree:"<<endl;
                for(auto i: output)
                cout<<i<<" "; 
                break;
        }
        case 12:
        {
            vector<int> output;
            output= topviewoftree(root);
            for(auto i: output)
            cout<<i<<" ";
            break;
        }
        case 13:
        {
            vector<int> output;
            output= bottomviewoftree(root);
            for(auto i: output)
            cout<<i<<" ";
            break;
        }
        case 14:
        {
            vector<int> output;
            // output= zigzagtraversal(root);
            vector<vector<int>> result;
            result= zigzagtraversalwithvector(root);
            for(auto i: result)
            {
                for(auto j: i){
                cout<<j<<" ";}
                cout<<endl;

            }
            // for(auto i: output)
            // cout<<i<<" ";
            // break;
        }
        case 15:
        {
            if(isbalanced(root).first)
            cout<<"Binary tree is a balanced tree"<<endl;
            else cout<<"Tree is not balanced"<<endl;
            break;
        }
        case 16:
        {
            vector<vector<int>> result;
            diagonaltraversal(root, result);
            for(auto i: result)
            {
                for(auto j: i)
                {
                    cout<<j<<" ";
                }
                cout<<endl;
            }
            break;
        }
        case 17:
        {
            Node *head= treetolist(root);
            displaylist(head);
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
//tree :   6 10 21 -1 -1 22 -1 12 -1 -1 19 6 -1 -1 9 -1 -1