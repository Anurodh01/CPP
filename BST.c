#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct  Node
{
    int data;
    struct Node *left, *right;
};
struct Node* createBST(struct Node *root, int inputdata)
{

    //if root is NULL
    if(root==NULL)
    {
        root= (struct Node*)malloc(sizeof(struct Node));
        root->data= inputdata;
        root->left= NULL; root->right=NULL;
        return root;
    }

    //as we know that binary search tree has a pattern that all left nodes data are smaller than root node and right node data are greater than root node
    if(inputdata < root->data)
    {
        root->left= createBST(root->left, inputdata);
    }

    //if the inputdata is greater than root data then insert in to its rright
    else{
        root->right= createBST(root->right, inputdata);
    }

    return root;
}

struct Node* searchinBST(struct Node *root, int key)
{
    //if root is null or searching reached at last
    if(root==NULL)
    {
        return NULL;
    }

    //if element found
    if(key == root->data)
    {
        return root;
    }
    //if the key given is less than root data then it will search in left or tree otherwise in right subtree
    if(key < root->data)
    {
        return searchinBST(root->left, key);
    }
    else{
        return searchinBST(root->right, key);
    }
}
int max(int a, int b)
{
    return a>b?a:b;   // if a is greater than b return a else return b; short cut :)

    //can also written as
    if(a>b)
    return a;
    else
    return b;
}
int heightofBST(struct Node *root)
{
    //if root is null
    if(root==NULL)
    {
        return 0;
    }

    //checking for left subtree height
    int left= heightofBST(root->left);
    //for right
    int right= heightofBST(root->right);

    //height of tree would be max(left, tree)+ one root node
    int height= max(left, right)+1;
    return height;
}

void nodetype(struct Node *root, int key)
{
    //if a element is leaf node then its external element else its internal element
    //here first need to find the element 

    //as you were talking now here i am returning address of that node from function :)
    struct Node *element= searchinBST(root, key);
    if(element==NULL || (element->left ==NULL && element->right==NULL))
    {
        printf("\nThe Node is a External/leaf Node.\n");
    }
    else{
        printf("\nThe Node is a Intenal/non-leaf node.\n");
    }
}

int LARGEST(struct Node *root )
{
    if(root==NULL)
    {
        return -1;
    }
    //iterate through the right side the max-element will be on right side of tree definitely as of BST property
    //same for the smallest element if you will just keep iteratint towards the left of tree the root of left subtree will be the min element

    struct Node *temp= root;
    while(temp->right!=NULL)
    {
        temp= temp->right;
    } 
    return temp->data;
}

struct Node* inorderpred(struct Node *root)
{
    while(root->right!=NULL)
    {
        root= root->right;
    }
    return root;
}
struct Node*  deletenode(struct Node* root, int key)
{
    if(root == NULL)
    return root;

    if(key < root->data)
    root->left= deletenode(root->left, key);
    else if(key > root->data)
    root->right= deletenode(root->right, key);
    else 
    {
        //if node is leaf node
        if(root->left==NULL && root->right==NULL)
        return NULL;

        //if node contains any left or right node i.e single node
        else if(root->left ==NULL)
        {
            struct Node *temp= root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct Node *temp= root->left;
            free(root);
            return temp;
        }

        //if node contains the both left and right node
        struct Node *temp= root->left;
        //finding inorder predecessor
        struct Node *pre= inorderpred(temp);
        root->data= pre->data;

        root->left= deletenode(root->left, pre->data);
    }
    return root;

    
}
void inorder(struct Node *root)
{
    if(root== NULL)
    return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    struct Node *root= NULL;
    int choice;
    while(true)
    {
        printf("1.Create BST. \n");
        printf("2.Display BST. \n");
        printf("3.Search in BST. \n");
        printf("4.Height of BST. \n");
        printf("5.Internal/extenal node.\n");
        printf("6.Maximum element from BST.\n");
        printf("0.EXIT: \n");
        printf("enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int inputdata;
                while(true)
                {
                
                printf("\nEnter the data to insert in BST,(-1 to stop): ");
                scanf("%d", &inputdata);
                if(inputdata == -1)
                {
                    break;
                }
                root= createBST(root, inputdata);
                }
                break;
            }
            case 2:
            {
                //to display the tree
                inorder(root);
                printf("\n");
                break;
            }
            case 3:
            {
                //to search in BST
                int key;
                printf("\nenter the element you want to search in BST: ");
                scanf("%d",&key);
                struct Node* ispresent=  searchinBST(root, key);
                if(ispresent!=NULL)
                printf("\nElement found.\n");
                else
                printf("\n Element not found.\n");
                break;
            }
            case 4:
            {
                int height= heightofBST(root);
                printf("Height of BST is: %d", height);
                break;
            }
            case 5:
            {
                int key;
                printf("\nEnter the node to determine for internal/external: ");
                scanf("%d",&key);
                nodetype(root, key);
                break;
            }
            case 6:
            {
                int maxelement= LARGEST(root);
                printf("The largest element of BST is: %d\n", maxelement);
                break;
            }
            case 7:
            {
                int delitem;
                printf("Enter the data to be deleted: \n");
                scanf("%d", &delitem);
                root= deletenode(root, delitem);
                break;
            }

            case 0:
                exit(0);
            default:
                printf("\nPlease enter a valid option.\n");
        }
    }
}

//tree : 63 39 99 36 38 41 77 117 89 110 119 -1