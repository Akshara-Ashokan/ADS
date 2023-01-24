#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};


struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if (root != NULL) {
        printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->key);
    }
}
struct node* search(struct node* root,int key){
        if (root==NULL || root->key == key)
                return root;
        if (root->key < key)
                return search(root->right, key);
        else
                return search(root->left, key);
}
struct node* insert(struct node* node, int key)
{
{
   if (node == NULL)
        return newNode(key);
   if (key < node->key)
        node->left = insert(node->left, key);
   else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}}
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
     while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }else{
        //Execute if root has both childs
                struct node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}
int main()
{
    struct node* root = NULL;
    struct node* temp=NULL;
    int choice,key;
while(choice!=-1){
        printf("Enter choice\n1.Insert\n2.Delete\n3.Search\n4.inorder\n5.preorder\n6.postorder\n-1.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:printf("Enter the key to insert:");
                scanf("%d",&key);
                if(root==NULL)
                        root=insert(root,key);
                else
                        insert(root,key);
                printf("The tree is elements are\n");
                        inorder(root);
                break;
        case 2:printf("Enter the key to delete:");
                scanf("%d",&key);
                root=deleteNode(root,key);
                printf("The tree is elements are\n");
                        inorder(root);
                break;
        case 3:printf("Enter the key to search:");
                scanf("%d",&key);
                temp=search(root,key);
                if(temp!=NULL)
                        printf("%d found in tree\n",key);
                else
                        printf("%d not found in tree\n",key);
                break;
        case 4:printf("The tree is elements are\n");
                inorder(root);
                break;
        case 5:printf("The tree is elements are\n");
                preorder(root);
                break;
        case 6:printf("The tree is elements are\n");
                postorder(root);
                break;
        default:printf("Exiting");
                break;
}
}
    return 0;
}
