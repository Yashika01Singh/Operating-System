#include <stdio.h>
#include <stdlib.h>
struct node {
    int val;
    struct node*left;
    struct node*right;
};
struct node* new (int value){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
struct node* insert (struct node *root , int value){

    if(root == NULL)
        {
            return new(value);
        }
    if (value < root->val)
        root->left = insert (root->left , value);
    if (value > root->val)
        root->right= insert (root->right , value);
    
    return root;

}
struct node* minNode(struct node *root){
    if(root==NULL)
        return NULL;
     if(root->left != NULL){
         return minNode(root->left);
     }
     return root;
}
struct node* delete(struct node *root , int value){
 
    if(root==NULL)
        return NULL;
    
    if(root->val > value)
        root->left = delete(root->left , value);
    else if (root->val < value)
        root->right = delete(root->right , value);
    
    else{

        if(root->left != NULL && root->right !=NULL){
            struct node *minRight = minNode(root->right);
            root->val = minRight->val;
            root->right = delete(root->right , minRight->val);
        }
        else if(root->left != NULL){
            struct node *temp;
            temp = root->left;
            free(root);
            return temp;}
        else if(root->right != NULL){
            struct node* temp;
            temp = root->right;
            free(root);
            return temp;
        }   

        else{
         free(root);
         return NULL;
        }

    }


}
int main(){

    struct node *root;
    root=NULL;
    int element;
    struct node *temp;
    
    int query;
    
    while(1){
        
        printf("\nEnter operation 1.Insert \n2.Delete \n3.Minimum Element \n4.quit\n");
        scanf("%d" , &query);
        if(query >4){
            printf("Invalid choice try again");
            continue;
        }
        if(query == 4){
            break;
        }
        if(query == 1){
            printf("\nEnter element to insert in BST : ");
            
            scanf("%d" , &element);
            root=insert(root , element);
            printf("\nelement inserted");

        }
        if(query == 2){
            printf("\nEnter element to delete from BST : ");
            
            scanf("%d" , &element);
            root=delete(root , element);
            printf("\nelement deleted");

        }
        if(query == 3){
            temp=minNode(root);
            printf("\nMinimum Element is : %d ", temp->val);
        }

    }
    
    //deleting the tree
    while(root!=NULL){
        root=delete(root , root->val);
    }
    
}
